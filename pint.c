#include"monty.h"
/**
 * pint_t - Print the top element of the stack
 * @head: A pointer to a pointer to the head of the stack
 * @lc: The line count of the script being executed
 *
 * Description: This function prints the top element of the stack.
 */
void pint_t(stack_t **head, unsigned int lc)
{
	if (head && stack_size(*head) == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lc);
		free_stack(head);
		free(glob.content);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
