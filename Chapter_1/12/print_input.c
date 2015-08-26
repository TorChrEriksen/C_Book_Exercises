#include <stdio.h>

// This program prints its input one word per line.
// A word is any combination of characters seperated with either a space or tab.
// Multiple spaces and/or tabs between words are filtered out so that only one
// single newline is printed.

main()
{
	int letter, doNewline;

	doNewline = 1;

	printf("Enter some text and watch the magic happen: ");
	while ((letter = getchar()) != EOF) {
		if (letter == ' ' || letter == '\t' || letter == '\n') {
			if (doNewline) {
				printf("\n");
				doNewline = 0;
			}
		}
		else {
			printf("%c", letter);
			doNewline = 1;
		}
	}
}
