#include <stdlib.h>
#include <stdio.h>

void main(int argc, char *argv[]){ 
	
	FILE *src, *dest;
	size_t read, write;
	char store[65536];
	
	if (argc != 3) {
		printf("\nPlease give command in the below format.\nUsage: ./cp <src> <dest>\n");
		return;
	}

	src = fopen(argv[1], "r");
	if (src == NULL) { 
		printf("\nsource File is empty or not exist.\n");
		return;
	}

	dest = fopen(argv[2], "w");

	printf("\ncopyiing the file...\n");
	
	while (1) {
		read = fread(store, 1, 65536, src);
		if (read == 0) break;
		write = fwrite(store, 1, read, dest);
		if (write == 0) break;
	}
	
	fclose(src);
	fclose(dest);
	
	printf("\nCopied succesfully.\n");
	return;
}
