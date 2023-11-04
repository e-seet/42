/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:23:38 by eseet             #+#    #+#             */
/*   Updated: 2023/09/08 19:23:40 by eseet            ###   ########.fr       */
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

// size_t strlcat(char *dst, const char *src, size_t size);

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	if (size > dst_len)
		src_len = dst_len + src_len;
	else
		src_len = src_len + size;
	while (src[i] != '\0' && size -1 > dst_len + i)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (src_len);
}
/*
// Custom strlcat function for testing purposes
// size_t custom_strlcat(char *dest, const char *src, size_t size) {
//     size_t dest_len = strlen(dest);
//     size_t src_len = strlen(src);
//     size_t total_len = dest_len + src_len;

//     if (size <= dest_len)
//         return total_len + size; 
// Destination buffer too small, return total length required.

//     strncat(dest, src, size - dest_len - 1); 
// Leave room for null-terminator
//     dest[size - 1] = '\0'; // Ensure null-termination

//     return total_len;
// }

int main() {
	char dest[20]; // Destination buffer

	// Test case 1: Basic Concatenation
	const char *src1 = "Hello, ";
	const char *src2 = "World!";
	size_t result1 = custom_strlcat(dest, src1, sizeof(dest));
	result1 = custom_strlcat(dest, src2, sizeof(dest)); 
	// Concatenate src2 to dest
	printf("Test Case 1: Concatenated %zu characters: %s\n", result1, dest);

	// Test case 2: Concatenate to an empty destination
	char empty_dest[10] = "";
	const char *src3 = "This is a test.";
	size_t result2 = custom_strlcat(empty_dest, src3, sizeof(empty_dest));
	printf("Test Case 2: Concatenated %zu characters
	 to empty dest: %s\n", result2, empty_dest);

	// Test case 3: Destination buffer is too small
	char small_dest[5] = "123";
	const char *src4 = "456789";
	size_t result3 = custom_strlcat(small_dest, src4, sizeof(small_dest));
	printf("Test Case 3: Concatenated %zu characters
	 to small dest: %s\n", result3, small_dest);

	return 0;
}*/
