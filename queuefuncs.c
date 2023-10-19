#include"monty.h"
/**
 * pushqueue - Push an element into a queue
 * @head: A pointer to the head of the queue
 * @n: The integer value to be pushed into the queue
 *
 * Description: places element with the specified value 'n' into
 * the queue represented by the 'head' pointer. It allocates memory for the new
 * element using malloc and adds it to the back of the queue.
 *
 * Return: A pointer to the newly created element (the back of the queue).
 */
stack_t *pushqueue(stack_t **head, int n)
{
	stack_t *newnode, *ptr;

	if (head == NULL)
		return (NULL);
	ptr = *head;
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	newnode->n = n;
	if (!ptr)
	{
		*head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
		return (newnode);
	}
	while (ptr && ptr->next)
		ptr = ptr->next;
	ptr->next = newnode;
	newnode->next = NULL;
	newnode->prev = ptr;
	return (newnode);
}
/**
 * popqueue - Remove and return the front element of a queue
 * @head: A pointer to the head of the queue
 *
 * Description: Removes and returns the front element of the queue
 * represented by the 'head' pointer. Updates the 'head' pointer to
 * point to the next element in the queue.
 *
 * Return: A pointer to the front element's integer value, or NULL if the
 * queue is empty.
 */
int popqueue(stack_t **head)
{
	stack_t *tmp;
	int x;

	if (!head || !*head)
		return (-1);
	tmp = *head;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	x = tmp->n;
	free(tmp);
	return (x);
}
