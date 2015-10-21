#include <stdio.h>
#include <stdlib.h>

#include "md5.h"


int usage(const char *prog_name){
	printf("Usage: %s <cache_path> URI1 [URI2 URI3 ...] \n", prog_name);
	return 1;
}

int check_and_remove(const char *filename){
	int ret;
	//printf("Checking %s ...\n", filename);
	ret = unlink(filename);
	return ret;
}

int main(int argc, char **argv){
    int i=0, j=0;
    unsigned char result[16]={0};
    char hex_result[33]={0};
    char filename[128]={0};
    char *cache_path = NULL;
    MD5_CTX ctx;
    if (argc < 3){
	return usage(argv[0]);
    }
    cache_path = argv[1];
    for(i=2; i<argc; i++){
	MD5_Init(&ctx);
	MD5_Update(&ctx, (void*)argv[i], strlen(argv[i]));
	MD5_Final(result, &ctx);
	for(j=0;j<16;j++){
	    sprintf(hex_result+j*2, "%02x", result[j]);
	}
	hex_result[32]=0;
	printf("%s\n", hex_result);
	sprintf(filename, "%s/%c/%c%c/%s", cache_path, hex_result[31], hex_result[29], hex_result[30], hex_result);
	//printf("Filename: %s\n", filename);
	printf("> %s -> %s [%d] \n", argv[i], filename,	check_and_remove(filename));
    }
}
