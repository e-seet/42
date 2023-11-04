/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:10:44 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 13:10:45 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parameter
// s:  The string from which to create the substring.
// start:  The start index of the substring in the
// string ’s’.
// len:  The maximum length of the substring.

//return
// The substring.
// NULL if the allocation fails.

//Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = (char *) malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

/*
// Prototype for the ft_substr function
// char *ft_substr(char const *s, unsigned int start, size_t len);
int main() {
    // Test case 1: Valid substring within the string
    const char *input1 = "Hello, World!";
    char *result1 = ft_substr(input1, 7, 5);
    assert(strcmp(result1, "World") == 0);
    free(result1);

    // // Test case 2: Start index out of bounds, should return an empty string
    const char *input2 = "Hello, World!";
    char *result2 = ft_substr(input2, 20, 5);
	// printf("%s\n", result2);
	assert(strcmp(result2, "") == 0);
    free(result2);

    // // Test case 3: Length longer than the 
	//remaining string, should return "World!"
    const char *input3 = "Hello, World!";
    char *result3 = ft_substr(input3, 7, 20);
    assert(strcmp(result3, "World!") == 0);
    free(result3);

    // // Test case 4: NULL input string, should return NULL
    const char *input4 = NULL;
    char *result4 = ft_substr(input4, 0, 5);
    assert(result4 == NULL);

    printf("All test cases passed!\n");

    return 0;
}
*/
