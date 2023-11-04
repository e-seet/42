/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:49:37 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 19:49:38 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strrchr() function returns a pointer to the last occurrence of
// the character c in the string s.

// The strchr() and strrchr() functions return a pointer to the matched
// character or NULL if the character is not found.

//The  terminating null byte is considered part of the string, so that
// if c is specified as '\0', these functions 
//return a pointer to the terminator.

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char) c)
			return ((char *)(&s[len]));
		len --;
	}
	return (0);
}

/*

int main() {
    // Test Case 1: Find the last occurrence of 'l' in a string
    //Last Occurrence of 'l' at position: 10
    // const char *str1 = "Hello, World!";
    // char searchChar1 = 'l';
    // char *result1 = ft_strrchr(str1, searchChar1);
    // if (result1 != NULL) {
    //     printf("Test Case 1: String: \"%s\",
    //     Last Occurrence of '%c' at position: %ld\n",
    //      str1, searchChar1, result1 - str1);
    // } else {
    //     printf("Test Case 1: Character '%c' 
	not found in the string \"%s\"\n",
    //     searchChar1, str1);
    // }

    // // Test Case 2: Find the last occurrence of 'o' in a string
    // // Last Occurrence of 'o' at position: 8
    // const char *str2 = "Hello, World!";
    // char searchChar2 = 'o';
    // char *result2 = ft_strrchr(str2, searchChar2);
    // if (result2 != NULL) {
    //     printf("Test Case 2: String: \"%s\", 
    //     //Last Occurrence of '%c' at position: %ld\n", str2,
    //      searchChar2, result2 - str2);
    // } else {
    //     printf("Test Case 2: Character '%c'
	 not found in the string \"%s\"\n",
    //      searchChar2, str2);
    // }

    // // Test Case 3: Find the last occurrence 
	//of a character not in the string
    // //Last Occurrence of 'o' at position: 8
    // const char *str3 = "Hello, World!";
    // char searchChar3 = 'x';
    // char *result3 = ft_strrchr(str3, searchChar3);
    // if (result3 != NULL) {
    //     printf("Test Case 3: String: \"%s\", 
	Last Occurrence of '%c' at position:
    //      %ld\n", str3, 
    //     searchChar3, result3 - str3);
    // } else {
    //     printf("Test Case 3: Character '%c' 
	not found in the string \"%s\"\n",
    //      searchChar3, str3);
    // }

	//extra test
	// const char *str4 = "teste";
	// char searchChar4 = 'e';
    // char *result4 = ft_strrchr(str4, searchChar4);
    // if (result4 != NULL) {
    //     printf("Test Case 4: String: \"%s\",
	Last Occurrence of '%c' at position: %ld\n", str4,
	 searchChar4, result4 - str4);
    // } else {
    //     printf("Test Case 3: Character '%c' 
	not found in the string \"%s\"\n", searchChar4, str4);
    // }

	// const char *str5 = "teste";
	// char searchChar5 = '\0';
    // char *result5 = ft_strrchr(str5, searchChar5);
    // if (result5 != NULL) {
    //     printf("Test Case 5: String: \"%s\", 
	Last Occurrence of '%c' at position: %ld\n", str5, searchChar5, 
	result5 - str5);
    // } else {
    //     printf("Test Case 5: Character '%c'
	 not found in the string \"%s\"\n", searchChar5, str5);
    // }

	// printf("other cases\n");
	// char *result6 = ft_strrchr(str5,  'e');
	 //: expected: 0x1026faf64, yours: 0x0
	// char *result7 = ft_strrchr( str5,  '\0'); 
	//: expected: 0x1026faf65, yours: 0x0
	// if (result6 != NULL) {
	// 	printf("result 6: %s\n", result6);
    // } else {
	// 	printf("result 6 is null");
    // }
	// if (result7 != NULL) {
	// 	printf("result 7: %s\n", result7);
    // } else {
	// 	printf("result 7 is null");
    // }

	char s[] = "tripouille";
	char *result8 = ft_strrchr(s, 't' + 256); 
	if (result8 != NULL) {
		printf("result 8: %s\n", result8);
    } else {
		printf("what is this? %c\n", 't' + 256);
		printf("result 8 is null");
    }
	return (0);
}
*/