#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @h: pointer to the head of the stack
 * @lc: line count
 * Return: void
 */
void mul(stack_t **h, unsigned int lc)
{
	stack_t *head = *h;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lc);
		fclose(glob.file);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	head->next->n *= head->n;
	pop(h);
}
