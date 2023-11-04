/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:40:24 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 19:40:25 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These functions convert lowercase letters to uppercase, and vice versa.
// If  c  is  a lowercase letter, toupper() returns its uppercase equivalent,
// The value returned is that of the converted letter, or c 
//if the conversion was not possible.

// int toupper(int c);
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c -32;
	return (c);
}

// int main() {
//     // Test Case 1: Convert a lowercase letter to uppercase
//     char lowercaseChar = 'a';
//     char uppercaseChar = toupper(lowercaseChar);
//     printf("Test Case 1: Original: %c, Uppercase: %c\n",
// lowercaseChar, uppercaseChar);

//     // Test Case 2: Convert an already uppercase letter
//     char uppercaseChar2 = 'Z';
//     char unchangedChar = toupper(uppercaseChar2);
//     printf("Test Case 2: Original: %c, Uppercase: %c (unchanged)\n",
// uppercaseChar2, unchangedChar);

//     // Test Case 3: Convert a non-letter character
//     char nonLetterChar = '1';
//     char unchangedChar2 = toupper(nonLetterChar);
//     printf("Test Case 3: Original: %c, Uppercase: %c (unchanged)\n",
// nonLetterChar, unchangedChar2);

//     return 0;
// }
