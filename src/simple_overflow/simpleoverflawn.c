// gcc -o lab1 vuln.c -fno-stack-protector -no-pie -z noexecstack

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int win(void)
{
    char flag[256];
    puts("You win! Here is your flag:");
    int fd = open("/flag", O_RDONLY);
    int n = read(fd, flag, sizeof(flag));
    write(0, flag, n);
    puts("\n");
}

int challenge(void)
{
    char input[111];
    puts("input:");
    int n = read(0, input, 4096);
    printf("Your entered: %s", input);
    puts("Goodbye!");
}

int main(void)
{
    puts("Good morning VA team :O");
    challenge();
}