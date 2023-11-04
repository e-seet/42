/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:59:26 by eseet             #+#    #+#             */
/*   Updated: 2023/09/14 18:59:27 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL

//parameter
//content: The content to create the node with.

//return 
// The new node

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = (void *) content;
	node->next = NULL;
	return (node);
}

/*
int main()
{
    t_list *newList = ft_lstnew("Test");
    printf("ft_lstnew Test: %s\n", 
	(char *) newList->content); // Expected output: "Test"

    t_list *newList2 = ft_lstnew("");
    printf("ft_lstnew2 Test: %s\n", 
	(char *) newList2->content); 
	
    t_list *newList3 = ft_lstnew(NULL);
    printf("ft_lstnew3 Test: %s\n", 
	(char *) newList3->content);
}*/