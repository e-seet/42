/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:12:48 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 13:12:49 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//parameter
// s1: The prefix string.
// s2: The suffix string.

//return
// The new string.
// NULL if the allocation fails.
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	size_t	i;
	size_t	j;
	char	*str;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc ((length + 1) * sizeof(char));
	if (!str)
		return (str);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

// int main() {
//     // Test Case 1: Join two empty strings
//     const char *empty1 = "";
//     const char *empty2 = "";
//     char *joined1 = ft_strjoin(empty1, empty2);
//     if (joined1 != NULL) {
//         printf("Joined string 1: \"%s\"\n", joined1);
//         free(joined1);
//     } else {
//         printf("Memory allocation failed for Test Case 1!\n");
//     }

//     // Test Case 2: Join an empty string with a non-empty string
//     const char *emptyStr = "";
//     const char *nonEmptyStr = "Hello";
//     char *joined2 = ft_strjoin(emptyStr, nonEmptyStr);
//     if (joined2 != NULL) {
//         printf("Joined string 2: \"%s\"\n", joined2);
//         free(joined2);
//     } else {
//         printf("Memory allocation failed for Test Case 2!\n");
//     }

//     // Test Case 3: Join two non-empty strings
//     const char *s1 = "Good";
//     const char *s2 = "morning!";
//     char *joined3 = ft_strjoin(s1, s2);
//     if (joined3 != NULL) {
//         printf("Joined string 3: \"%s\"\n", joined3);
//         free(joined3);
//     } else {
//         printf("Memory allocation failed for Test Case 3!\n");
//     }

//     return 0;
// }