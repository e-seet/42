/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:48:38 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 19:48:38 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int main() {
//     // Test Case 1: Calculate the length of a non-empty string
//     // Test Case 1: String: "Hello, World!", Length: 13
//     const char *str1 = "Hello, World!";
//     size_t length1 = ft_strlen(str1);
//     printf("Test Case 1: String: \"%s\", Length: %zu\n", str1, length1);

//     // Test Case 2: Calculate the length of an empty string
//     //Test Case 2: String: "", Length: 0
//     const char *str2 = "";
//     size_t length2 = ft_strlen(str2);
//     printf("Test Case 2: String: \"%s\", Length: %zu\n", str2, length2);

//     // Test Case 3: Calculate the length of a string with spaces
//     //Test Case 3: String: "   Spaces   ", Length: 12
//     const char *str3 = "   Spaces   ";
//     size_t length3 = ft_strlen(str3);
//     printf("Test Case 3: String: \"%s\", Length: %zu\n", str3, length3);

//     return 0;
// }
