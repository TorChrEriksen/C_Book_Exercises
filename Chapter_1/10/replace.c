#include <stdio.h>

// This program copies input to output and replaces tabs with \t,
// backspaces with \b, and backslashes with \\.

main()
{
	int cur_char;

	printf("Enter your input\n\n");
	
	while ((cur_char = getchar()) != EOF) {
		if (cur_char == '\t')
			printf("\\t");
		else if (cur_char == '\b')
			printf("\\b");
		else if (cur_char == '\\')
			printf("\\\\");
		else
			putchar(cur_char);
	}
}
