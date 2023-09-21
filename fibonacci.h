#include <stdio.h>
#include <stdlib.h>

void validate_number_of_terms(int terms)
{
	if (terms <= 0) {
		printf("\t.:: Number of terms must be a positive and non-zero number!\n");
		exit(1);
	}
}

void check_memory_allocation(int *fib)
{
	if (!fib) {
		printf("\t.:: Not enough space in memory to store the terms of the Fibonacci Series!\n");
		exit(1);
	}
}

void fibonacci()
{
	int *fib;
	unsigned long int terms;

	printf("\n\t.:: Enter the number of terms to display in the Fibonacci series: ");
	scanf("%ld", &terms);
	validate_number_of_terms(terms);

	fib = (int *)calloc(terms, sizeof(int));
	check_memory_allocation(fib);

	fib[0] = 0;
	fib[1] = 1;

	for (int index = 2; index < terms; index++) {
			fib[index] = fib[index - 1] + fib[index - 2];
	}

	printf("\t.:: Fibonacci series for %ld numbers: {", terms);
	for (int index = 0; index < terms; index++) {
		printf(" %d ", fib[index]);
	}
	printf("}\n\n");

	free(fib);
}