// gcc -o app_safe app_safe.c -I./zlib -L./zlib -lz -Wl,-rpath,'$ORIGIN/zlib'

#include <zlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    unsigned char in[4096];
    int n = read(0, in, sizeof(in));

    uLongf out_len = compressBound(n);      // zlib computes the exact safe size
    unsigned char *out = malloc(out_len);

    int ret = compress2(out, &out_len, in, n, Z_BEST_COMPRESSION);
    if (ret == Z_OK)
        printf("Compressed %d -> %lu bytes\n", n, out_len);

    free(out);
    return 0;
}