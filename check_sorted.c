#include "push_swap.h"

int check_sorted(node_t *stack)
{
	node_t *temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}