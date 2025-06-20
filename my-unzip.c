#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void dekompressoi(char *aNimi);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("my-unzip: komennon käyttö my-unzip <tiedostot>\n");
		exit(1);
	}
	
	for (int i = 1; i < argc; i++) {
		dekompressoi(argv[i]);
	}

	return 0;
}

void dekompressoi(char *aNimi) {
	FILE *Tiedosto = NULL;
	uint32_t iMaara = 0;
	char cMerkki = '\0';

	if ((Tiedosto = fopen(aNimi, "rb")) == NULL) {
		perror("my-unzip: virhe, tiedoston luku epäonnistui");
		exit(1);
	}

	while (fread(&iMaara, sizeof(uint32_t), 1, Tiedosto) != 0 && 
			fread(&cMerkki, sizeof(char), 1, Tiedosto) != 0) {
		for (int i = 0; i < iMaara; i++) {
			printf("%c", cMerkki);
		}	
	}

	fclose(Tiedosto);
	return;
}
