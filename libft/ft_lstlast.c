/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:13:26 by eseet             #+#    #+#             */
/*   Updated: 2023/09/14 19:13:27 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parameter: lst: The beginning of the list
// return the last node
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	if (curr == NULL)
		return (NULL);
	else
	{
		while (curr -> next != NULL)
		{
			curr = curr -> next;
		}
		return (curr);
	}
}

/*
void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = *lst;
    new -> next = temp;
    *lst = new;
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
        printf("node->%s\n", 
		(char *)current->content);
        current = current->next;
    }
}
int main()
{
	 //test case 1:
    // t_list *list = NULL;

	//test case 2
 	t_list *list = NULL;
    ft_lstadd_front(&list, ft_lstnew("Front"));
    ft_lstadd_front(&list, ft_lstnew("NewFront1"));
    ft_lstadd_front(&list, ft_lstnew("NewFront2"));
    ft_lstadd_front(&list, ft_lstnew("NewFrontlasts"));
   
	displayList(list);
    t_list *last = ft_lstlast(list);
    printf("ft_lstlast Test: %s\n", 
	(char *)last->content); // Expected output: "Front"
   
	return 0;
}*/
