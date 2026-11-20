#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
	printf("Total arguments: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	FILE *fptr = fopen(argv[0], "rb");
	if (fptr == NULL) {
		perror("Error opening file");
		return 1;
	}
	unsigned char toc[1];
	fread(toc, 1, 1, fptr);	
	uint8_t config = (toc[0] >> 3) & 0x1F;
	uint8_t stereo = (toc[0] >> 2) & 0x1;
	fclose(fptr);
	return 0;
}
