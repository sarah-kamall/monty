#include"monty.h"
/**
 * push_t - add node to the stack
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void push_t(stack_t **head, unsigned int count)
{
	int n, i = 0, fnum = 0; /* fnum to check if an elemnt entered isnt num*/

	if (glob.arg)
	{
		if (glob.arg[0] == '-')
			i++;
		for ( ; glob.arg[i] != '\0'; i++)
		{
			if (glob.arg[i] > 57 || glob.arg[i] < 48)
				fnum = 1;
		}
		if (fnum == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n%s", count, glob.arg);
			fclose(glob.file);
			free(glob.content);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: 2usage: push integer\n", count);
		fclose(glob.file);
		free(glob.content);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	n = atoi(glob.arg);
	push(head, n);
}

