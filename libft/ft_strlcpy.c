/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:02:51 by eseet             #+#    #+#             */
/*   Updated: 2023/09/08 18:02:52 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
// The strlcpy() and strlcat() functions copy and concatenate strings
// respectively. They are designed to be safer, more consistent, and
// less error prone replacements for strncpy(3) and strncat(3).
// Unlike those functions, strlcpy() and strlcat()  take the full
//size of the buffer (not just the length) and guarantee to NULL 
// terminate the result (as long as size is larger than 0 or, in 
// the case of strlcat(), as long as there is at least one byte
// free in dst).  Note that a byte for the NUL should be included
// in size.  Also note that strlcpy() and strlcat() only operate on
//true “C” strings.  This means that for strlcpy() src must be NUL
//terminated and for strlcat() both src and dst must be NUL-terminated.

// The strlcpy() function copies up to size - 1 characters from the
// NUL-terminated string src to dst, NUL-terminating the result.

// The strlcat() function appends the NUL-terminated string src to
// the end of dst. It will append at most size- strlen(dst) - 1 bytes,
// NUL-terminating the result.

// RETURN VALUES
// The strlcpy() and strlcat() functions return the total length of
// the string they tried to create. For strlcpy() that means the
// length of src. For strlcat() that means the initial length of
// dst plus the length of src. While this may seem somewhat 
// confusing, it was done to make truncation detection simple.

// Note, however, that if strlcat() traverses size characters 
// without finding a NUL, the length of the string is considered
//to be size and the destination string will not be NUL-terminated 
// (since there was no space for the NUL).  This keeps strlcat() 
// from running off the end of a string.  In practice this should
//  not happen (as it means that either size is incorrect or that
// dst is not a proper “C” string).  The check exists to prevent 
// potential security problems in incorrect code.

// strlcpy(char *dst, const char *src, size_t size);

#include "libft.h"

// essentially
// 1. make a copy 
// 2. return length of src
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (!size)
		return (len);
	if (len >= size)
		len = size - 1;
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (ft_strlen(src));
}

/*
int main() {
	char dest[20];  // Destination buffer

	// Test case 1: Basic Copy
	const char *src1 = "Hello, World!";
	size_t result1 = ft_strlcpy(dest, src1, sizeof(dest));
	printf("Test Case 1: Copied %zu characters: %s\n", result1, dest);

	// Test case 2: Copy a longer string
	const char *src2 = "This is a longer string";
	size_t result2 = ft_strlcpy(dest, src2, sizeof(dest));
	printf("Test Case 2: Copied %zu characters: %s\n", result2, dest);

	// Test case 3: Copy an empty string
	const char *src3 = "";
	size_t result3 = ft_strlcpy(dest, src3, sizeof(dest));
	printf("Test Case 3: Copied %zu characters: %s\n", result3, dest);

	// Test case 4: Copy with insufficient destination buffer size
	const char *src4 = "This is a longer string";
	size_t result4 = ft_strlcpy(dest, src4, 10); 
	// Only 9 characters + null-terminator fit
	printf("Test Case 4: Copied %zu characters with size 10: %s\n",
	 result4, dest);

	return 0;
}*/
