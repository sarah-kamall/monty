#include"monty.h"
/**
 * pop_t - Remove the top element of the stack
 * @head: A pointer to a pointer to the head of the stack
 * @lc: The line count of the script being executed
 *
 * Description: This function removes the top element of the stack.
 */
void pop_t(stack_t **head, unsigned int lc)
{
	(void)lc;
	pop(head);
}
