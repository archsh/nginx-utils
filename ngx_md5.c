#include <stdio.h>
#include <stdlib.h>

#include "md5.h"

int main(int argc, char **argv){
    int i=0, j=0;
    unsigned char result[16]={0};
    MD5_CTX ctx;
    //printf("Hello, Boy!\n");
    for(i=1; i<argc; i++){
	//printf("[%d]: %s \n", i, argv[i]);
	MD5_Init(&ctx);
	MD5_Update(&ctx, (void*)argv[i], strlen(argv[i]));
	MD5_Final(result, &ctx);
	//printf("[%d]%s > ", i, argv[i]);
	for(j=0;j<16;j++)printf("%02x", result[j]);
	printf("\n");
    }
}
