/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:32 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 12:56:33 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int memcmp(const void *s1, const void *s2, size_t n);
// The memcmp() function compares the first n bytes
// (each interpreted as unsigned char) of the memory areas s1 and s2.
// The  memcmp() function returns an integer less than, equal to, 
//or greater than zero if the first n bytes of s1 is found,
// respectively, to be less than, to match, or 
//be greater than the first n bytes of s2.

// For a nonzero return value, the sign is determined by the sign of
//the difference between the first pair of bytes (inter‐
// preted as unsigned char) that differ in s1 and s2.

// If n is zero, the return value is zero.
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr;
	const unsigned char	*ptr2;
	size_t				i;

	ptr = s1;
	ptr2 = s2;
	i = 0;
	while (n > i)
	{
		if (ptr[i] == ptr2[i])
		{
			i++;
		}
		else
		{
			return (ptr[i] - ptr2[i]);
		}
	}
	return (0);
}

/*
int main() {
	// Test 1: Compare two equal strings [0]
	const char str1[] = "Hello, World!";
	const char str2[] = "Hello, World!";
	int result1 = memcmp(str1, str2, sizeof(str1));
	printf("Test 1: Comparing equal strings result: %d\n", result1);

	// Test 2: Compare two different strings [2]
	const char str3[] = "Hello, Universe!";
	int result2 = memcmp(str1, str3, sizeof(str1));
	printf("Test 2: Comparing different strings result: %d\n", result2);

	// Test 3: Compare two equal integer arrays [0]
	int array1[] = {1, 2, 3, 4, 5};
	int array2[] = {1, 2, 3, 4, 5};
	int result3 = memcmp(array1, array2, sizeof(array1));
	printf("Test 3: Comparing equal integer arrays result: %d\n", result3);

	// Test 4: Compare two different integer arrays [-4]
	int array3[] = {5, 4, 3, 2, 1};
	int result4 = memcmp(array1, array3, sizeof(array1));
	printf("Test 4: Comparing different integer arrays result: %d\n", result4);
	return 0;
}*/
