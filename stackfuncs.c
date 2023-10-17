#include"monty.h"
/**
 * push - Push a new element onto the stack.
 * @head: A pointer to a pointer to the head of the stack.
 * @n: The value to be pushed onto the stack.
 * Return: A pointer to the new element, or NULL on failure.
 */
stack_t *push(stack_t **head, int n)
{
	stack_t *newnode;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;
	if (*head)
		(*head)->prev = newnode;
	*head = newnode;
	return (*head);
}
/**
 * pop - Pop the top element from the stack.
 * @head: A pointer to a pointer to the head of the stack.
 * Return: The value of the popped element, or -1 if the stack is empty.
 */
int pop(stack_t **head)
{
	stack_t *popped;
	int tmp;

	if (head == NULL || *head == NULL)
		return (-1);
	popped = *head;
	*head = popped->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	tmp = popped->n;
	free(popped);
	return (tmp);
}
/**
 * stack_size - Get the size of a stack.
 * @h: A pointer to the head of the stack.
 *
 * Return: The number of elements in the stack.
 */
int stack_size(stack_t *h)
{
	int s;
	stack_t *head;

	head = h;
	s = 0;
	while (head)
	{
		s++;
		head = head->next;
	}
	return (s);
}
/**
 * free_stack - Frees all elements of a stack.
 * @head: A pointer to a pointer to the head of the stack.
 *
 * Description: This function frees all elements of the stack
 * and sets the head to NULL.
 */
void free_stack(stack_t **head)
{
	stack_t *node, *temp;

	if (!head)
		return;
	node = *head;
	while (node)
	{
		temp = node;
		node = node->next;
		pop(&temp);
	}
}
