/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:34:35 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 15:34:36 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//       void bzero(void *s, size_t n);

#include "libft.h"

//can use memset to do this
//eg: ft_memset(s, 0, n);
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (n > i)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*

int main() { 
	// Test case 1: Basic usage 
	char buffer1[10] = "abcdefghi";
	ft_bzero(buffer1, sizeof(buffer1));
	for (int i = 0; i < (int)sizeof(buffer1); i++) {
		assert(buffer1[i] == '\0');
	}

	// Test case 2: Zeroing out part of a buffer
	char buffer2[10] = "abcdefghij";
	ft_bzero(buffer2, 5);
	for (int i = 0; i < 5; i++) {
		assert(buffer2[i] == '\0');
	}
	//this return size of buffer allocated and not the number of items
	// printf("%ld\n", sizeof(buffer2) );
	for (int i = 5; i < (int)sizeof(buffer2); i++) {
		assert(buffer2[i] == 'f' + (i - 5));
	} 

	// Test case 3: Zeroing out an empty buffer 
	char buffer3[0]; 
	ft_bzero(buffer3, 0); // Should not cause any issues 
	// You can't access buffer3 because it has zero size 
	printf("All test cases passed.\n"); 
	return 0; 
}
*/