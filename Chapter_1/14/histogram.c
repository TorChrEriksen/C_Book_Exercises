#include <stdio.h>

#define CHAR_MAX 128

// This program prints a histogram that shows the frequencies of
// different characters in its input.
// The program does not show ASCII values 0-32 (NUL - SPACE) or 127 (DEL).

main()
{
	int i, stdc[CHAR_MAX];
	for (i = 0; i < CHAR_MAX; ++i)
		stdc[i] = 0;

	while ((i = getchar()) != EOF) {
		++stdc[i];
	}

	// Locate the most frequent character encountered.
	int hFreq = 0;
	for (i = 33; i < CHAR_MAX - 1; ++i) {
		if (stdc[i] > hFreq)
			hFreq = stdc[i];
	}

	int k, printArray[CHAR_MAX][hFreq];
	for (i = 0; i < CHAR_MAX; ++i) {
		for (k = 0; k < hFreq; ++k) {
			if (stdc[i] > k )
				printArray[i][k] = 1;
			else
				printArray[i][k] = 0;
		}
	}

	printf("\n------+");
	for (i = 33; i < CHAR_MAX - 1; ++i)
		putchar('-');
	putchar(',');
	printf("\n%6d|", hFreq+1);
	for (i = 33; i < CHAR_MAX -1; ++i)
		putchar(' ');
	printf("|\n");
	
	for (k = hFreq-1; k >= 0; --k) {
		printf("%6d|", k+1);
		for (i = 33; i < CHAR_MAX - 1; ++i) {
			if (printArray[i][k])
				printf("+");
			else
				printf(" ");
		}
		printf("|\n");
	}

	printf("------+");
	for (i = 33; i < CHAR_MAX - 1; ++i)
		putchar('-');
	printf("/\n char  ");
	for (i = 33; i < CHAR_MAX - 1; ++i)
		printf("%c", i);
	printf("\n\n");
}
