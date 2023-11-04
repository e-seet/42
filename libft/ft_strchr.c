/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:02:45 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 19:02:46 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strchr() function returns a pointer to the first 
// occurrence of the character c in the string s.

//RETURN VALUE
// The strchr() functions return a pointer to the matched character 
//or NULL if the character is not found.  The  terminating
// null byte is considered part of the string, so that 
//if c is specified as '\0', these functions return a pointer to the terminator.
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == (char)c)
	{
		return ((char *) s);
	}
	else
		return (NULL);
}
/*

int main() {
    char str[] = "Hello, World!";
    char *result;

    // Test Case 1: Search for 'o' in str
    // Found 'o' at position 4
    result = ft_strchr(str, 'o'); 
    if (result != NULL) {
        printf("Test Case 1: Found 'o' at position %ld\n",
         result - str);
    } else {
        printf("Test Case 1: 'o' not found\n");
    }

    // Test Case 2: Search for 'X' in str
    //'X' not found
    result = ft_strchr(str, 'X');
    if (result != NULL) {
        printf("Test Case 2: Found 'X' at position %ld\n", result - str);
    } else {
        printf("Test Case 2: 'X' not found\n");
    }

    // Test Case 3: Search for '\0' (null terminator) in str
    // Found null terminator at position 13
    result = ft_strchr(str, '\0');
    if (result != NULL) {
        printf("Test Case 3: Found null terminator at position %ld\n",
         result - str);
    } else {
        printf("Test Case 3: Null terminator not found\n");
    }

    return 0;
}*/