#include "monty.h"

/**
 * pchar - Print the top element of the stack
 * @head: A pointer to a pointer to the head of the stack
 * @lc: The line count of the script being executed
 *
 * Description: This function prints the top element of the stack.
 * Return: 0 on success, 1 on failure
 */
void pchar(stack_t **head, unsigned int lc)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lc);
		free_stack(head);
		free(glob.content);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lc);
		free_stack(head);
		free(glob.content);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
