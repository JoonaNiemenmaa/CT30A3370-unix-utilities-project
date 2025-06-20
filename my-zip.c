#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void kompressoi(char *aNimi);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("my-zip: komennon käyttö my-zip <tiedostot>\n");
		exit(1);
	}
	
	for (int i = 1; i < argc; i++) {
		kompressoi(argv[i]);
	}

	return 0;
}

void kompressoi(char *aNimi) {
	FILE *Tiedosto = NULL;
	char *aRivi = NULL;
	char cMerkki = '\0';
	uint32_t iMaara = 0;
	char *ptr = NULL;
	size_t iKoko = 0;

	if ((Tiedosto = fopen(aNimi, "r")) == NULL) {
		perror("my-zip: virhe, tiedoston luku epäonnistui");
		exit(1);
	}

	while (getline(&aRivi, &iKoko, Tiedosto) != -1) {
		iMaara = 0;
		ptr = aRivi;
		cMerkki = *ptr;
		while (*ptr != '\0') {
			if (*ptr == cMerkki) {
				iMaara++;
			} else if (cMerkki != '\0') {
				fwrite(&iMaara, sizeof(uint32_t), 1, stdout);
				fwrite(&cMerkki, sizeof(char), 1, stdout);
				iMaara = 1;
				cMerkki = *ptr;
			}
			ptr++;
		}
	}

	free(aRivi);
	fclose(Tiedosto);
	return;
}
