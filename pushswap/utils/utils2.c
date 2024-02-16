
#include "utils.h"

int	countElementsinStack(t_node *head)
{
	int	i;
	
	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

