#define _GNU_SOURCE 1

#include <stdio.h>
#include <unistd.h>
#include <lzo/lzo1x.h>

int main(void)
{
    setvbuf(stdin,  NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    unsigned char input[4096];
    lzo_uint in_len = read(0, input, sizeof(input));

    unsigned char compressed[4096 + 4096 / 16 + 64 + 3];
    lzo_uint out_len;
    lzo_align_t wrkmem[LZO1X_1_MEM_COMPRESS / sizeof(lzo_align_t)];

    lzo_init();

    /* Only compresses — lzo1x_decompress() is never called, so the
       CVE-2014-4607 attack surface does not exist in this binary. */
    lzo1x_1_compress(input, in_len, compressed, &out_len, wrkmem);

    write(1, compressed, out_len);
}
