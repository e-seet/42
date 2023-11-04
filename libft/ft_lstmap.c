/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:28:02 by eseet             #+#    #+#             */
/*   Updated: 2023/09/14 19:28:03 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parameter
// lst: The address of a pointer to a node.

// f: The address of the function used to iterate on
// the list.

// del: The address of the function used to delete
// the content of a node if needed.

// //return
// The new list. NULL if the allocation fails.

// description
// 1. Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. 
// 2. Creates a new list resulting of the successive
// applications of the function ’f’. 
// 3.The ’del’ function is used to delete the content
// of a node if needed. [basically if there is a error]

//So basically
// 1. Get the content (after function)
// 2. create new node
// 3. check if node created successfully
// 3.1 if not, delete the node and content
// 4. if yes, add the node to the list
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*list;	
	void	*content;

	if (!f || !lst || !del)
		return (0);
	list = 0;
	while (lst)
	{
		content = f(lst -> content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			ft_lstclear(&newnode, del);
			del(content);
		}
		ft_lstadd_back(&list, newnode);
		lst = lst -> next;
	}
	return (list);
}

/*
void *map(void *content) {
	return strdup((char *)content);
}
void del(void *content)
{
	free(content);
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
    // Create a sample linked list with integers
    t_list *lst = NULL;
    t_list *lst2 = NULL;

	ft_lstadd_front(&lst, ft_lstnew("Front"));
	 ft_lstadd_back(&lst, ft_lstnew("Back1"));
	 ft_lstadd_back(&lst, ft_lstnew("Back2"));
	 ft_lstadd_back(&lst, ft_lstnew("Back3"));
	 ft_lstadd_back(&lst, ft_lstnew("Back4"));

    // Print the original and mapped lists for verification
    printf("Original list: ");
    displayList(lst);
	
    // Call ft_lstmap to apply the mapping function
   	lst2 = ft_lstmap(lst, map, del);

    printf("\nMapped list: ");
   	displayList(lst2);
    return 0;
}*/
