/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:23:43 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 17:23:45 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memchr()  function scans the initial n bytes of the memory area
// pointed to by s for the first instance of c.
// Both c and the bytes of the memory area pointed to by s
// are interpreted as unsigned char.
//returnN VALUE
//The memchr() and memrchr() functions return a pointer to the matching byte
//or NULL if the character does not occur in  the  given
//memory area.

// void *memchr(const void *s, int c, size_t n);
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ptr;
	size_t				i;

	ptr = (unsigned char *) s;
	i = 0;
	while (n > i)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void *)(ptr + i));
		i++;
	}
	return (0);
}
/*

int main(void){

    const char *str = "Hello, World!"; 

    // Test case 1: Search for 'A' in a string 
    char searchChar1 = 'A'; 
    const void *result1 = ft_memchr(str, searchChar1, strlen(str)); 
    if (result1 != NULL) { 
        printf("'%c' found at position %ld in the string.\n",
searchChar1, (char *)result1 - str); 
    } else {
        printf("'%c' not found in the string.\n", searchChar1); 
    } 

    // // Test case 2: Search for 'o' in a string 
    char searchChar2 = 'o'; 
    const void *result2 = ft_memchr(str, searchChar2, strlen(str)); 
    if (result2 != NULL) { 
        printf("'%c' found at position %ld in the string.\n",
searchChar2, (char *)result2 - str); 
    } else {
        printf("'%c' not found in the string.\n", searchChar2); 
    } 

    // // Test case 3: Search for 'X' in a string 
    char searchChar3 = 'X'; 
    const void *result3 = ft_memchr(str, searchChar3, strlen(str)); 
    if (result3 != NULL) { 
        printf("'%c' found at position %ld in the string.\n",
searchChar3, (char *)result3 - str); 
    } else { 
        printf("'%c' not found in the string.\n", searchChar3); 
    } 

    return 0; 
}
*/