#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	FILE* ptr_winter, * ptr_winter_numbering;
	
	char fname1[] = "winter.txt";
	char fname2[40];
	char word[20];
	int count = 0;

	printf("Введите новое имя файла: ");
	scanf("%s", fname2);

	if ((ptr_winter = fopen(fname1, "rt")) == NULL) { printf("Ошибка открытия файла"); return -1; }

	if ((ptr_winter_numbering = fopen(fname2, "wt")) == NULL) { printf("Ошибка открытия файла"); return -1; }


	while (fscanf(ptr_winter, "%s", word) != EOF) {

		count += 1;

		fprintf(ptr_winter_numbering,"%d. %s\n", count, word);
	}

	fclose(ptr_winter);
	fclose(ptr_winter_numbering);

	return 0;
}