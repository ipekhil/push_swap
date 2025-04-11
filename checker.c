#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int is_sorted(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i] > arr[i + 1])
			return 0;
	return 1;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);

	int *stack = malloc((argc - 1) * sizeof(int));
	if (!stack)
		return 1;

	for (int i = 1; i < argc; i++)
		stack[i - 1] = atoi(argv[i]);

	char buffer[BUFFER_SIZE];
	int size = argc - 1;

	while (fgets(buffer, BUFFER_SIZE, stdin))
	{
		buffer[strcspn(buffer, "\n")] = '\0'; // Satır sonunu sil

		if (strcmp(buffer, "sa") == 0 ||
			strcmp(buffer, "sb") == 0 ||
			strcmp(buffer, "ss") == 0 ||
			strcmp(buffer, "pa") == 0 ||
			strcmp(buffer, "pb") == 0 ||
			strcmp(buffer, "ra") == 0 ||
			strcmp(buffer, "rb") == 0 ||
			strcmp(buffer, "rr") == 0 ||
			strcmp(buffer, "rra") == 0 ||
			strcmp(buffer, "rrb") == 0 ||
			strcmp(buffer, "rrr") == 0)
			continue;

		if (strlen(buffer) == 0)
			continue;

		write(2, "Error\n", 6);
		free(stack);
		return 1;
	}

	if (is_sorted(stack, size))
		printf("OK\n");
	else
		printf("KO\n");

	free(stack);
	return 0;
}
