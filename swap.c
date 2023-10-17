#include"monty.h"
/**
 * swap_t - Swap the top two elements of the stack
 * @head: A pointer to a pointer to the head of the stack
 * @linenum: The line number in the script being executed
 *
 * Description: This function swaps the top two elements of the stack.
 */
void swap_t(stack_t **head, unsigned int linenum)
{
	int s, tmp;
	stack_t *node;

	s = stack_size(*head);
	if (s < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", linenum);
		free_stack(head);
		free(glob.content);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	node = *head;
	tmp = node->n;
	node = (*head)->next;
	(*head)->n = node->n;
	node->n = tmp;
}
