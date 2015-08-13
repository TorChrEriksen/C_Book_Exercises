#include <stdio.h>

// This program copies input to output and replaces consequtive blanks with a single blank.

main()
{
	int cur_char, prev_char;

	printf("Enter your input\n\n");
	
	while ((cur_char = getchar()) != EOF) {
		if ((cur_char == ' ') && (prev_char == ' '))
			continue;
		else
			putchar(cur_char);

		prev_char = cur_char;
	}
}
