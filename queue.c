#include"monty.h"
/**
 * isqueue - Check if the stack is empty and set it as a queue
 * @head: A pointer to a pointer to the head of the stack/queue
 * @linenum: The line number in the script being executed
 *
 * Description: This function checks if the stack is empty. If it is empty, it
 * now on.
 *
 */
void isqueue(stack_t **head, unsigned int linenum)
{
	(void)linenum;
	(void)head;

	glob.isqueue = 1;
}
/**
 * isstack - Check if the queue is empty and set it as a stack
 * @head: A pointer to a pointer to the head of the stack/queue
 * @lc: The line count of the script being executed
 *
 * Description: This function checks if the queue is empty. If it is empty, it
 * from now on.
 */
void isstack(stack_t **head, unsigned int lc)
{
	(void)head;
	(void)lc;
	glob.isqueue = 0;
}
