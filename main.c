#include <stdio.h>

int main() {
	FILE *fptr = fopen("example.txt", "rb");
	fclose(fptr);
	return 0;
}
