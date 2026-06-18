# Notes

- fd: https://en.wikipedia.org/wiki/File_descriptor
- x86-64 registers: https://math.hws.edu/eck/cs220/f22/registers.html
- gdb x command: https://visualgdb.com/gdbreference/commands/x

## Setting suid bit
```bash
sudo chown root:root ./simple_overflow
sudo chmod 4755 ./simple_overflow
ls -l ./simple_overflow           
```


## simple overflow
1. run with `test`
2. show rsp in the stack
3. overflow
4. show rsp with aaaaaaaaaaa
5. 
...
99. `cat payload.txt | ./simple_overflow`

## canary
1. run with test
2. run with overflow to show what the canary does
3. run with 73 bytes to leak canary
4. second stage test payload including the canary to show that it doesnt trigger anymore
5. 