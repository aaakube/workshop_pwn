from pwn import *

def debug(argv):
    p = process(argv=argv)

    gdb.attach(p, gdbscript='''
        b main
    ''')

    payload = b'A'*128

    p.sendlineafter(b"what's your name? ", payload)

    p.interactive()

def main(argv):

    p = process(argv=argv)

    p.interactive()


if __name__ == "__main__":
    context.arch = "amd64"
    context.terminal = ['tmux', 'splitw', '-h']
    context.log_level='debug'

    argv = ['./binary-exploitation-canary-bypass']

    # main(argv)
    debug(argv)