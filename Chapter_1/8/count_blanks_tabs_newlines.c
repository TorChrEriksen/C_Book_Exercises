#include <stdio.h>

// This program count the number of blanks, tabs and newlines.
// Signal EOF: Ctrl+D (Unix), Ctrl+Z (Windows).

main()
{
	int c, blanks, tabs, newlines;

	blanks = 0;
	tabs = 0;
	newlines = 0;

	printf("Enter a text that contains blanks, tabs and newlines.\n\n");
	
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blanks;
		else if (c == '\t')
			++tabs;
		else if ( c == '\n')
			++newlines;
		else
			continue;
	}

	printf("\nThe following was counted\n");
	printf("-------------------------\n");
	printf("%-11s%d\n%-11s%d\n%-11s%d\n\n",
	       "Blanks", blanks,
	       "Tabs", tabs,
	       "Newlines", newlines);
}
