/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:57:08 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 14:57:09 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//The  memcpy() function copies n bytes from memory area
// src to memory area dest.
//The memory areas must not overlap.Use memmove(3)
//if the memory areas do overlap.

// RETURN VALUE
//        The memcpy() function returns a pointer to dest.

// void *memcpy(void *dest, const void *src, size_t n);
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destptr;
	const unsigned char	*srcptr;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (0);
	srcptr = src;
	destptr = dest;
	while (n > i)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	return ((void *)destptr);
}

/*
int main() { 
	// Test Case 1: Test copying a string 
	char source[] = "Hello, World!"; 
	char destination[20];
	// my_memcpy(destination, source, sizeof(source)); 
	ft_memcpy(destination, source, sizeof(source)); 
	assert(strcmp(source, destination) == 0);

	// Test Case 2: Test copying an integer array 
	int sourceArray[] = {1, 2, 3, 4, 5}; int destinationArray[5];
	// my_memcpy(destinationArray, sourceArray, sizeof(sourceArray));
	ft_memcpy(destinationArray, sourceArray, sizeof(sourceArray));
	for (int i = 0; i < 5; i++)
	{
		assert(sourceArray[i] == destinationArray[i]); 
	}

	//personal testcase
	char buffer[20] = "Hello, World!";
    // Overlapping memory copy
    ft_memcpy(buffer + 6, buffer, 7);
    // Printing the result
    printf("personal testcase: %s\n", buffer);


	printf("All tests passed!\n"); 
	return 0; 
}*/