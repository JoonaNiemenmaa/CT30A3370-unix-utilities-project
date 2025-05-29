#include <stdio.h>
#include <stdlib.h>

#define RIVI 255

void tulostaTiedosto(char *aNimi);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("my-cat: tiedostoa ei voitu avata.\n");
		exit(0);
	}
	
	for (int i = 1; i < argc; i++) {
		tulostaTiedosto(argv[i]);
	}

	return 0;
}

void tulostaTiedosto(char *aNimi) {
	FILE *Tiedosto = NULL;
	char aRivi[RIVI] = "";

	if ((Tiedosto = fopen(aNimi, "r")) == NULL) {
		perror("my-cat: virhe, tiedoston luku epäonnistui");
		exit(1);
	}

	while (fgets(aRivi, RIVI, Tiedosto) != NULL) {
		printf("%s", aRivi);	
	}

	fclose(Tiedosto);
	return;
}
