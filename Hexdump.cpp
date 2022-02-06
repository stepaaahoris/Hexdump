#include <stdio.h>

int main() {
	FILE* soubor = fopen("ASCII-tabulka.txt", "w");

	if (soubor == NULL) {
		printf("Chyba: Soubor nelze otevřít pro zápis.\n");
		return 1;
	}

	int tabulka = 0x40;

	fprintf(soubor, "Znak     Hex\n\n");

	for (int i = 0; i < 26; i++) {
		tabulka += 1;
		fwrite(&tabulka, sizeof(int), 1, soubor);
		fprintf(soubor, "     0x%x\n", tabulka);
	}

	if (fclose(soubor) == EOF) {
		printf("Chyba: Soubor se nepodařilo otevřít.\n");
		return 1;
	}

	return(0);
}