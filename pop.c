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
	if (stack_size(*head) == 0)
	{
		printf("L%d: can't pop an empty stack\n", lc);
		free_stack(head);
		free(glob.content);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	if (glob.isqueue == 0)
		pop(head);
	else
		popqueue(head);
}
