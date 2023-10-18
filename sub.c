#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @h: pointer to the head of the stack
 * @lc: line count
 * Return: void
 */
void sub(stack_t **h, unsigned int lc)
{
	stack_t *head = *h;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lc);
		fclose(glob.file);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	head->next->n -= head->n;
	pop(h);
}
