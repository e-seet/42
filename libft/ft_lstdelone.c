/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:18:04 by eseet             #+#    #+#             */
/*   Updated: 2023/09/14 19:18:05 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//parameter
// lst: The node to free.
// del: The address of the function used to delete
// the content.

// description
// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	del(lst->content);
	free(lst);
}

/*
// Function to display the content of a linked list
void displayList(t_list *lst) {
	t_list *current = lst;
	while (current != NULL) {
		printf("node -> %s\n", (char *)current->content);
		current = current->next;
	}
}
t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = (void *) content;
	node->next = NULL;
	return (node);
}
void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = *lst;
	new -> next = temp;
	*lst = new;
}

int main() {

   // Test ft_lstadd_front
	t_list *list = NULL;
	ft_lstadd_front(&list, ft_lstnew("Front"));
	ft_lstdelone(list, del);
	displayList(list); // Expected output: "NewFront -> Back -> NULL"

	ft_lstadd_front(&list, ft_lstnew("NewFront"));
	ft_lstdelone(list, del);
   
	displayList(list); // Expected output: "NewFront -> Back -> NULL"


	return 0;
}
*/