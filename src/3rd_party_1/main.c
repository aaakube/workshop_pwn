// gcc -o app_vuln app_vuln.c -I./zlib -L./zlib -lz -Wl,-rpath,'$ORIGIN/zlib'


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zlib.h>

int main(void)
{
    unsigned char extra_buf[64];
    gz_header header;
    memset(&header, 0, sizeof(header));
    header.extra = extra_buf;
    header.extra_max = sizeof(extra_buf);   // app does everything "right"

    unsigned char in[4096];
    int n = read(0, in, sizeof(in));        // attacker-controlled gzip stream

    z_stream strm = {0};
    inflateInit2(&strm, 16 + MAX_WBITS);
    inflateGetHeader(&strm, &header);       // <-- the CVE-2022-37434 code path

    unsigned char out[4096];
    strm.next_in = in;   strm.avail_in = n;
    strm.next_out = out; strm.avail_out = sizeof(out);
    inflate(&strm, Z_NO_FLUSH);             // overflow triggers here

    puts("Done.");
    return 0;
}