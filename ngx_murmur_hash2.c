#include <stdio.h>
#include <string.h>

typedef unsigned int uint32_t;
typedef unsigned char u_char;

uint32_t
ngx_murmur_hash2(u_char *data, size_t len)
{
    uint32_t  h, k;

    h = 0 ^ len;

    while (len >= 4) {
        k  = data[0];
        k |= data[1] << 8;
        k |= data[2] << 16;
        k |= data[3] << 24;

        k *= 0x5bd1e995;
        k ^= k >> 24;
        k *= 0x5bd1e995;

        h *= 0x5bd1e995;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len) {
    case 3:
        h ^= data[2] << 16;
    case 2:
        h ^= data[1] << 8;
    case 1:
        h ^= data[0];
        h *= 0x5bd1e995;
    }

    h ^= h >> 13;
    h *= 0x5bd1e995;
    h ^= h >> 15;

    return h;
}

int usage(const char *cmd){
	printf("Usage:   %s <string 1...n>\n", cmd);
	printf("         string: strings seperated by space.\n");
}

int main(int argc, char **argv){
	uint32_t i=0;

	if(argc < 2){
		return usage(argv[0]);
	}
	for(i=1;i<argc;i++){
		printf("%s\t%08x\n", argv[i], ngx_murmur_hash2(argv[i], strlen(argv[i])));
	}
	
}