#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @h: pointer to the head of the stack
 * @lc: line count
 *
 * Return: void
 */
void rotr(stack_t **h, unsigned int lc)
{
	stack_t *head = *h, *tail = *h, *temp = NULL;

	(void)lc;
	if (head == NULL || head->next == NULL)
		return;
	while (tail->next != NULL)
		tail = tail->next;
	temp = tail->prev;
	temp->next = NULL;

	tail->next = head;
	tail->prev = NULL;

	head->prev = tail;
	*h = tail;

	/* 1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL */
	/* 5 <-> 1 <-> 2 <-> 3 <-> 4 -> NULL */
}
