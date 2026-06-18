from pwn import *

def debug(argv):
    p = process(argv=argv)

    gdb.attach(p, gdbscript='''
        b main
    ''')

    payload = ''

    with open('payload.txt', 'wb') as f:
        f.write(payload)


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