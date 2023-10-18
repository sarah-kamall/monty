#include "monty.h"
/**
 * exec - Execute commands based on 'content' and manipulate the stack
 * @content: A string containing the command to execute
 * @stack: A pointer to a pointer to a stack data structure
 * @count: An unsigned integer representing the current execution count
 * @f: A pointer to a file for input/output operations
 * Return: 0 upon success
 */
int exec(char *content, stack_t **stack, unsigned int count, FILE *f)
{
	instruction_t instruc[] = {{"push", push_t}, {"pall", pall},	 {"pop", pop_t},
														 {"swap", swap_t}, {"pint", pint_t}, {"add", add},
														 {NULL, NULL}};
	unsigned int i;
	char *cmand;

	i = 0;
	cmand = strtok(content, " \t\n");
	/* skip if comment */
	if (cmand && cmand[0] == '#')
		return (0);
	glob.arg = strtok(NULL, " \t\n");
	while (cmand && instruc[i].opcode)
	{
		if (strcmp(cmand, instruc[i].opcode) == 0)
		{
			instruc[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (cmand && instruc[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, cmand);
		fclose(f);
		free_stack(stack);
		free(content);
		exit(EXIT_FAILURE);
	}
	return (1);
}
