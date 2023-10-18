#include "monty.h"
info glob = {NULL, NULL, NULL};
/**
 * main - main func
 * @argc: num of args
 * @argv: string of args
 * Description: This is the main function where program execution begins.
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *f;
	ssize_t readline;
	char *content;
	size_t size;
	unsigned int linecount;
	stack_t *stack;

	stack = NULL;
	linecount = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	glob.file = f; /* clang-format off */
	do {
		content = NULL;
		readline = getline(&content, &size, f);
		glob.content = content;
		linecount++;
		if (readline > 0)
			exec(content, &stack, linecount, f);
		free(content);
	} while (readline > 0); /* clang-format on */
	free_stack(&stack);
	fclose(f);
	return (0);
}
