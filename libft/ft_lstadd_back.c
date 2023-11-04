/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:16:21 by eseet             #+#    #+#             */
/*   Updated: 2023/09/14 19:16:22 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parameter
// lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.

#include "libft.h"
// add node to the back
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = *lst;
	if (curr == NULL && new == NULL)
		return ;
	else if (curr == NULL && new != NULL)
	{
		*lst = new;
	}
	else
	{
		while (curr -> next != NULL)
		{
			curr = curr -> next;
		}
		curr -> next = new;
	}
}

/*

int main()
{
	
	t_list *list = NULL;
    ft_lstadd_front(&list, ft_lstnew("Front"));
    ft_lstadd_front(&list, ft_lstnew("NewFront"));
  
    ft_lstadd_back(&list, ft_lstnew("Back"));
    displayList(list); 
	return 0;
}
*/