#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to the top of the stack
 * @lc: line count
 * Return: void
 */
void pstr(stack_t **head, unsigned int lc)
{
	stack_t *h = *head;
	(void)lc;

	while (h && h->n > 0 && h->n < 128)
	{
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
