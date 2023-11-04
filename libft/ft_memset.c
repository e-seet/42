/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:53:34 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 18:53:34 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//The memset() function fills the first n bytes
//of the memory area pointed to by s with the constant byte c.

// RETURN VALUE
//The memset() function returns a pointer to the memory area s.

#include "libft.h"

// void *memset(void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n)
	{
		ptr[n - 1] = (char) c;
		n --;
	}
	return (s);
}

// int main() {
//     char buffer[20];

//     // Test Case 1: Set the entire buffer to 'A'
//		 (ASCII 65) AAAAAAAAAAAAAAAAAAAA
//     ft_memset(buffer, 'A', sizeof(buffer));
//     printf("Test Case 1: %s\n", buffer);

//     // Test Case 2: Set the first 10 bytes to 'B'
//		 (ASCII 66) BBBBBBBBBBAAAAAAAAAA
//     ft_memset(buffer, 'B', 10);
//     printf("Test Case 2: %s\n", buffer);

//     // Test Case 3: Set a portion of the buffer to '\0'
//		 (null terminator) BBBBB
//     ft_memset(buffer + 5, '\0', 5);
//     printf("Test Case 3: %s\n", buffer);

//     // Test Case 4: Set a portion of the buffer to 0 (binary zero) BBBBB
//     ft_memset(buffer + 10, 0, 5);
//     printf("Test Case 4: %s\n", buffer);

//     return 0;
// }