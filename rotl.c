#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @h: pointer to the head of the stack
 * @lc: line count
 *
 * Return: void
 */
void rotl(stack_t **h, unsigned int lc)
{
	stack_t *head = *h, *tail = *h, *temp = NULL;

	(void)lc;
	if (head == NULL || head->next == NULL)
		return;
	while (tail->next != NULL)
		tail = tail->next;
	temp = head->next;
	temp->prev = NULL;

	head->next = NULL;
	head->prev = tail;

	tail->next = head;
	*h = temp;

	/* 1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL */
	/* 2 <-> 3 <-> 4 <-> 5 <-> 1 -> NULL */
}
