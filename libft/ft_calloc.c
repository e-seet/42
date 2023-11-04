/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:56:58 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 15:56:59 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//       void *calloc(size_t nmemb, size_t size);
// don't need to check parameters
// malloc function in C, as defined by the C standard,
// will return a null pointer (NULL) if it fails to allocate memory
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int main() { 

	// Test case 1: Allocate an array of integers
	// and verify the contents are initialized to zero. 

	size_t num_elements = 5; 
	int *arr = (int *)ft_calloc(num_elements, sizeof(int)); 

	if (arr == NULL) { 
		perror("Memory allocation failed"); 
		return 1; 
	}
	for (size_t i = 0; i < num_elements; i++) { 
		assert(arr[i] == 0); 
	}

	// Test case 2: Allocate an array of characters 
and verify the contents are initialized to zero. 
	size_t num_chars = 10; 
	char *str = (char *)ft_calloc(num_chars, sizeof(char)); 
	if (str == NULL) { 
		perror("Memory allocation failed"); 
		return 1; 
	} 

	for (size_t i = 0; i < num_chars; i++) { 
		assert(str[i] == '\0'); 
	} 

	// Test case 3: Allocate an empty block (size zero) and ensure it's NULL. 
	void *empty_block = ft_calloc(0, 1); 
	assert(empty_block == NULL); 

	// Test case 4: Allocate a large block of memory and verify it's not NULL. 
	size_t large_size = 1 << 20; // 1 megabyte 
	void *large_memory = ft_calloc(large_size, 1); 
	assert(large_memory != NULL); 

	// Clean up allocated memory 
	free(arr); 
	free(str); 
	free(empty_block); 
	free(large_memory); 
	printf("All test cases passed.\n"); 
	return 0; 
}
*/