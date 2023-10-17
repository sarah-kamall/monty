#include"monty.h"
/**
 * pall - Print all values on the stack
 * @h: A pointer to the head of the stack
 * @lc: The line count of the script being executed
 *
 * Description: This function prints all values on the stack,
 * starting from the top.
 */
void pall(stack_t **h, unsigned int lc)
{
	stack_t *head;

	(void)lc;
	head = *h;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
