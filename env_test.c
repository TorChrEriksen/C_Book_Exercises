#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec t1;
	t1.tv_sec = 0;
	t1.tv_nsec = 100000000L;

	printf("\nTime to get started!\n");

	int i, k;
	long secondsAsNano = 1000000000L;

	for (i = 3; i > 0; i--)
	{
		printf("%d", i);
		fflush(stdout);
		for (k = 0; k < secondsAsNano/t1.tv_nsec; k++)
		{
			nanosleep(&t1, NULL);
			printf(".");
			fflush(stdout);

		}
		printf("\n");
	}
	printf("GO!\n\n");
	return 1;
}
