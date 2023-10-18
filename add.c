#include "monty.h"

/**
 * add - Add the top two elements of the stack
 * @head: A pointer to a pointer to the head of the stack
 * @lc: The line count of the script being executed
 *
 * Description: Adds the two elements at the top of the stack.
 * and stores the result in the second element from the top.
 */
void add(stack_t **head, unsigned int lc)
{
	int size = stack_size(*head);
	stack_t *stack_head = *head;
	int sum = 0;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lc);
		free_stack(head);
		free(glob.content);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	sum = stack_head->n + stack_head->next->n;
	stack_head->next->n = sum;
	pop(head);
}
