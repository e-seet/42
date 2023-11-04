/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:45:54 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 19:45:55 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These functions convert lowercase letters to uppercase, and vice versa.
// int tolower(int c);
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

// int main() {
//     // Test Case 1: Convert an uppercase letter to lowercase
//     char uppercaseChar = 'A';
//     char lowercaseChar = tolower(uppercaseChar);
//     printf("Test Case 1: Original: %c, Lowercase: %c\n",
// uppercaseChar, lowercaseChar);

//     // Test Case 2: Convert an already lowercase letter
//     char lowercaseChar2 = 'z';
//     char unchangedChar = tolower(lowercaseChar2);
//     printf("Test Case 2: Original: %c, Lowercase: %c (unchanged)\n",
// lowercaseChar2, unchangedChar);

//     // Test Case 3: Convert a non-letter character
//     char nonLetterChar = '9';
//     char unchangedChar2 = tolower(nonLetterChar);
//     printf("Test Case 3: Original: %c, Lowercase: %c (unchanged)\n",
// nonLetterChar, unchangedChar2);

//     return 0;
// }
