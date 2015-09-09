#include <stdio.h>

// This program prints a histogram of the lengths of words in its input.
// Words longer than 10 characters are for now listed as 10+.
// Zero length words are just whitespaces, tabs, etc.

// TODO: Does not handle characters like æ,ø,å very well (counts as two characters it seems).

main()
{
	// state = 0 : waiting for word to start.
	// state > 0 : currently counting a word.
	int i, state;
	int nWords[11];

	state = 0;

	for (i = 0; i < 11; ++i)
		nWords[i] = 0;

	i = 0;

	while ((i = getchar()) != EOF) {
		if (i == ' ' || i == '\t' || i == '\n') {
			
			if (state > 0 && state < 10)
				++nWords[state];
			else if (state >= 10)
				++nWords[10];
			else if (state < 0)
				printf("An error occured.");
			else
				;
			
			++nWords[0];
			state = 0;
		}
		else {
			++state;
		}
	}

	// For now print out data
	/* for (i = 0; i < 11; ++i) */
	/* 	printf("Words of length %3d:%d\n", i, nWords[i]); */

	// Printed histogram should look something in order of this:
	// 8|                               |
	// 7|          __                __ |
	// 6|          __    __          __ |
	// 5|    __    __    __          __ |
	// 4|    __ __ __    __    __    __ |
	// 3| __ __ __ __ __ __    __ __ __ |
	// 2| __ __ __ __ __ __    __ __ __ |
	// 1| __ __ __ __ __ __ __ __ __ __ |
	//--|-------------------------------|
	// #|  1  2  3  4  5  6  7  8  9 10+

	// Locate the highest word count (ignore whitespaces since they will be very large).
	int lWord = 0;
	for (i = 1; i < 11; ++i) {
		if (nWords[i] > lWord)
			lWord = nWords[i];
	}

	int k, printArray[11][lWord];
	for (i = 0; i < 11; ++i) {
		for (k = 0; k < lWord; ++k) {
			if (nWords[i] > k )
				printArray[i][k] = 1;
			else
				printArray[i][k] = 0;
		}
	}

	// Print the histogram represented by printArray[][]
	// Starting with the highest number so we need to loop backwards through lWord.
	// We leave all the zero length words out (whitespaces etc).
	printf("\n%2d|                               |\n", lWord+1);
	for (k = lWord-1; k >= 0; --k) {
		printf("%2d|", k+1);
		for (i = 1; i < 11; ++i) {
			if (printArray[i][k])
				printf(" ++");
			else
				printf("   ");
		}
		printf(" |\n");
	}

	printf("--|-------------------------------|\n");
	printf(" #|  1  2  3  4  5  6  7  8  9 10+\n\n");
}
