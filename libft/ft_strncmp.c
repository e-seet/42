/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:46:21 by eseet             #+#    #+#             */
/*   Updated: 2023/09/08 17:46:21 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
// The  strcmp() function compares the two strings s1 and s2.  
// The locale is not taken into account 
//(for a locale-aware comparison, see strcoll(3)).
// The comparison is done using unsigned characters.
// strcmp() returns an integer indicating 
//the result of the comparison, as follows:
// • 0, if the s1 and s2 are equal;
// • a negative value if s1 is less than s2;
// • a positive value if s1 is greater than s2.

// The strncmp() function is similar, except it compares only
// the first (at most) n bytes of s1 and s2.

// RETURN VALUE
// The strcmp() and strncmp() functions return an integer less than,
// equal to, or greater than zero if s1  (or the first n bytes thereof) is
// found, respectively, to be less than, to match, or be greater than s2.

// int strncmp(const char *s1, const char *s2, size_t n);

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (n > i && (str1[i] || str2[i]))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((*(unsigned char *)(str1 + i)
				- *(unsigned char *)(str2 + i)));
	}
	return (0);
}
/*
void testStringComparison(const char *str1, const char *str2, int n) {
    int result = ft_strncmp(str1, str2, n);
    
    if (result == 0) {
        printf("Both strings are equal up to %d characters.\n", n);
    } else if (result < 0) {
        printf("str1 is less than str2 up to %d characters.\n", n);
		printf("result is %d\n", result);
    } else {
        printf("str1 is greater than str2 up to %d characters.\n", n);
		printf("result is %d\n", result);
    }
}

int main() {
    // // Test case 1: Equality: Expected S1 > S2
    // char str1_1[] = "Hello, World!";
    // char str2_1[] = "Hello, Earth!";
    // int n_1 = 13;  // Compare the entire strings
    // testStringComparison(str1_1, str2_1, n_1);

    // // Test case 2: Partial equality: [Equal]
    // char str1_2[] = "apple pie";
    // char str2_2[] = "apple juice";
    // int n_2 = 5;  // Compare the first 5 characters
    // testStringComparison(str1_2, str2_2, n_2);

    // // Test Case 3: [equal]
    // char str1_3[] = "programming";
    // char str2_3[] = "program";
    // int n_3 = 7;  // Compare the first 7 characters
    // testStringComparison(str1_3, str2_3, n_3);

    // // Test case 4: [s1> s2]
    // char str1_4[] = "programming";
    // char str2_4[] = "program";
    // int n_4 = 10;  // Compare the first 10 characters
    // testStringComparison(str1_4, str2_4, n_4);

    // // Test case 5: Opposite of test case 4 [s2>s1]
    // char str1_5[] = "program";
    // char str2_5[] = "programming";
    // int n_5 = 10;  // Compare the first 10 characters
    // testStringComparison(str1_5, str2_5, n_5);

	//extra tesst
	testStringComparison("test\200", "test\0", 6); //expected 1
	// testStringComparison("","",2); //
    return 0;
}
*/