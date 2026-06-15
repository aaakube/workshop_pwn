#define _GNU_SOURCE 1

#include <stdio.h>
#include <unistd.h>
#include <lzo/lzo1x.h>

int main(void)
{
    setvbuf(stdin,  NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    unsigned char compressed[4096];
    lzo_uint in_len = read(0, compressed, sizeof(compressed));

    unsigned char output[128];
    lzo_uint out_len = sizeof(output);

    lzo_init();

    /* CVE-2014-4607: lzo1x_decompress() performs no output-buffer bounds
       checking — a crafted compressed stream overflows the stack buffer. */
    lzo1x_decompress(compressed, in_len, output, &out_len, NULL);

    write(1, output, out_len);
}
