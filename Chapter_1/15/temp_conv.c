#include <stdio.h>

void display_fahr_cels_table(int, int, int);

main()
{
	display_fahr_cels_table(0, 300, 20);
}

void display_fahr_cels_table(int lower, int upper, int step)
{
	float fahr, celsius;
	
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
