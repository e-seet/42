/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:59:57 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 19:59:58 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strnstr() function locates the first occurrence of the null-terminated
//  string little in the string big, 
//where not more than len characters are searched.  

// Characters that appear after a ‘\0’ character are not searched.
// Since the strnstr() function is a FreeBSD specific API, 
//it should only be used when portability is not a concern.

// RETURN VALUES
// If needle is an empty string, haystack is returned; if needle occurs
// nowhere in haystack, NULL is returned; otherwise a pointer to the first
// character of the first occurrence of needle is returned.

// EXAMPLES
// The following sets the pointer ptr to the "Bar Baz" portion of
// largestring:

//    const char *largestring = "Foo Bar Baz";
//    const char *smallstring = "Bar";
//    char *ptr;

//    ptr = strstr(largestring, smallstring);

// The following sets the pointer ptr to NULL, because only the first 4
// characters of largestring are searched:

//    const char *largestring = "Foo Bar Baz";
//    const char *smallstring = "Bar";
//    char *ptr;

//    ptr = strnstr(largestring, smallstring, 4);

// char * strnstr(const char *haystack, const char *needle, size_t len);

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*find;

	str = (char *) haystack;
	find = (char *) needle;
	i = 0;
	if (!*find)
		return ((char *)str);
	while (str[i] && len > i)
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (str[i + j] == find[j] && len > i + j)
			{
				j++;
				if (find[j] == '\0')
					return (str + i);
			}
		}
		i++;
	}
	return (NULL);
}
/*
int main() {
	// // Test case 1: Search for a substring present 
	// //in the string within the specified length
	// const char *haystack1 = "Hello, World!";
	// const char *needle1 = "World";
	// size_t max_length1 = 12; 
	//  // Limit the search to the first 12 characters
	// char *result1 = strnstr(haystack1, needle1, max_length1);

	// if (result1 != NULL) {
	// 	printf("Test case 1 passed. Found substring: %s\n", result1);
	// } else {
	// 	printf("Test case 1 failed. Substring not found.\n");
	// }

	// // Test case 2: Search for a substring present
	// // in the string within the specified length
	// // Test case fail.
	// const char *haystack2 = "Hello, World!";
	// const char *needle2 = "World";
	// size_t max_length2 = 10;  
	// // Limit the search to the first 10 characters
	// char *result2 = strnstr(haystack2, needle2, max_length2);

	// if (result2 != NULL) {
	// 	printf("Test case 2 passed. Found substring: %s\n", result2);
	// } else {
	// 	printf("Test case 2 failed. Substring not found.\n");
	// }

	// // Test case 3: Search for a substring not 
	// //present in the string within the specified length
	// // fail as it does not exist
	// const char *haystack3 = "This is a test.";
	// const char *needle3 = "foobar";
	// size_t max_length3 = 15;  
	// // Limit the search to the first 15 characters
	// char *result3 = strnstr(haystack3, needle3, max_length3);

	// if (result3 == NULL) {
	// 	printf("Test case 3 passed. Substring not found.\n");
	// } else {
	// 	printf("Test case3  failed. Found unexpected substring: %s\n", result2);
	// }

	// // Test case 4:
	// const char *haystack4 = "Hello, World!";
	// const char *needle4 = "ell";
	// size_t max_length4 = 10; 
	//  // Limit the search to the first 12 characters
	// char *result4 = strnstr(haystack4, needle4, max_length4);

	// if (result4 != NULL) {
	// 	printf("Test case 4 passed. Found substring: %s\n", result4);
	// } else {
	// 	printf("Test case 4 failed. Substring not found.\n");
	// }

	char *str;
	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
		printf("NULL\n");
    else
		printf("%s\n", str);

	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	printf( "resykt %s\n", ft_strnstr(haystack, needle, -1)); //haystack + 1)
	printf("result %s\n", ft_strnstr(haystack, "abcd", 9)); // haystack + 5
	printf( "result %s\n",  ft_strnstr(haystack, "cd", 8)) ; //NULL

	return 0;
}
*/
