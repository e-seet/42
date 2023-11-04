/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:01:42 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 18:01:42 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//parameter
// s: The string on which to iterate.
// f: The function to apply to each character.
// the function take in unsigned int and char

// return
// The string created from the successive applications of ’f’.
// Returns NULL if the allocation fails.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
char uppercase_mapper(unsigned int index, char c) {
    // Check if the character is lowercase
    if (c >= 'a' && c <= 'z') {
        // Convert to uppercase
        return c - 'a' + 'A';
    }
    return c; // Leave other characters unchanged
}

char	mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
int main() {
    // // Test Case 1: Map characters to uppercase
    // const char *input1 = "Hello, World!";
    // char *result1 = ft_strmapi(input1, uppercase_mapper);

    // if (result1 != NULL) {
    //     printf("Test Case 1: Original String: %s\n", input1);
    //     printf("Mapped String 1: %s\n", result1);
    //     free(result1);
    // } else {
    //     printf("Memory allocation failed for Test Case 1!\n");
    // }

    // // Test Case 2: NULL input string
    // const char *input2 = NULL;
    // char *result2 = ft_strmapi(input2, uppercase_mapper);

    // if (result2 == NULL) {
    //     printf("Test Case 2: NULL input string handled correctly.\n");
    // } else {
    //     printf("Test Case 2: Expected NULL result for NULL input.\n");
    //     free(result2);
    // }

	char *str;
	char	*strmapi;

	strcpy(str, "LoReM iPsUm");
    strmapi = ft_strmapi(str, &mapi);
    printf("r:%s\n",strmapi);
    if (strmapi == str)
        printf("\nA new string was not returned");
    if (strmapi[11] != '\0')
        printf("\nString is not null terminated");

    return 0;
}
*/