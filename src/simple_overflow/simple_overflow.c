#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void win(void)
{
    char flag[256];

    puts("You win! Here is your flag:");

    int fd = open("/flag", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "ERROR: Failed to open the flag -- %s!\n", strerror(errno));
        if (geteuid() != 0)
            fprintf(stderr, "  Run the suid binary directly to get the right permissions!\n");
        exit(1);
    }

    int n = read(fd, flag, sizeof(flag));
    if (n <= 0) {
        fprintf(stderr, "ERROR: Failed to read the flag -- %s!\n", strerror(errno));
        exit(1);
    }

    write(STDOUT_FILENO, flag, n);
    puts("\n");
}

void challenge(void)
{
    char input[111];

    puts("input:");

    int n = read(STDIN_FILENO, input, 4096);
    if (n < 0) {
        fprintf(stderr, "ERROR: Failed to read input -- %s!\n", strerror(errno));
        exit(1);
    }

    puts("Goodbye!");
}

int main(void)
{
    setvbuf(stdin,  NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    challenge();
}
