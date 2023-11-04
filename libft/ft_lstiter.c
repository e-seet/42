/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:26:06 by eseet             #+#    #+#             */
/*   Updated: 2023/09/14 19:26:06 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parameter
// lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.

// description
// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst || !f)
		return ;
	curr = lst;
	while (curr -> next != NULL)
	{
		f(curr -> content);
		curr = curr -> next;
	}
	f(curr -> content);
}

/*
void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = *lst;
    new -> next = temp;
    *lst = new;
}

// Test ft_lstmap
void *map(void *content) {
	return strdup((char *)content);
}
void del(void *content)
{
	free(content);
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
void displayList(t_list *lst) {
    t_list *current = lst;
    while (current != NULL) {
        printf("node-> %s \n", (char *)current->content);
        current = current->next;
    }
}

int main()
{
    t_list *list = NULL;

    ft_lstadd_front(&list, ft_lstnew("Front"));
    ft_lstadd_front(&list, ft_lstnew("NewFront"));
	ft_lstadd_front(&list, ft_lstnew("NewFront3"));
	displayList(list);
    ft_lstiter(list, print); // Expected output: "Item1" and "Item2"

	return 0;
}
*/