#include "monty.h"

/**
 * mod - computes the modules of the second top element of the stack
 * by the top element of the stack
 * @h: pointer to the head of the stack
 * @lc: line count
 * Return: void
 */
void mod(stack_t **h, unsigned int lc)
{
	stack_t *head = *h;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lc);
		fclose(glob.file);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lc);
		fclose(glob.file);
		free_stack(h);
		exit(EXIT_FAILURE);
	}

	head->next->n %= head->n;
	pop(h);
}
