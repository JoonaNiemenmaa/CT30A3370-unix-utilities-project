#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARAMETRIT 2

void haeRivit(char *aHaku, FILE *Tiedosto);

int main(int argc, char **argv) {
	if (argc < PARAMETRIT) {
		printf("my-grep: komennon käyttö my-grep <haku> <tiedostot>\n");
		exit(1);
	}

	FILE *Tiedosto = NULL;

	if (argc == 2) {
		haeRivit(argv[1], stdin);
	} else {
		for (int i = 2; i < argc; i++) {
			if ((Tiedosto = fopen(argv[i], "r")) == NULL) {
				perror("my-grep: tiedoston avaaminen epäonnistui");
				exit(1);
			}

			haeRivit(argv[1], Tiedosto);

			fclose(Tiedosto);
		}
	}
	

	return 0;
}

void haeRivit(char *aHaku, FILE *Tiedosto) {
	char *aRivi = NULL;
	size_t iPituus = 0;
	char *ptr1 = NULL, *ptr2 = NULL;
	int iPituusHaku = 0;

	iPituusHaku = strlen(aHaku);

	while (getline(&aRivi, &iPituus, Tiedosto) != -1) {
		ptr1 = aRivi;
		ptr2 = aHaku;
		while (*ptr1 != '\0') {
			if (*ptr1 == *ptr2) {
				ptr2++;
			} else {
				ptr2 = aHaku;
			}
			if (*ptr2 == '\0') {
				printf("%s", aRivi);
				break;
			}
			ptr1++;
		}

	}

	free(aRivi);
	return;
}
