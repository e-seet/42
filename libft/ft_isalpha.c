/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:02:38 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 17:02:38 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//       int isalpha(int c);
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)
	)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
int main() { 
	// Test case 1: Alphabetic characters (letters) 
	assert(ft_isalpha('A') != 0); 
	assert(ft_isalpha('a') != 0); 
	assert(ft_isalpha('Z') != 0); 
	assert(ft_isalpha('z') != 0); 

	// Test case 2: Non-alphabetic characters 
	assert(ft_isalpha('0') == 0);    // Digit 
	assert(ft_isalpha('9') == 0);    // Digit 
	assert(ft_isalpha(' ') == 0);    // Space 
	assert(ft_isalpha('@') == 0);    // Special character 
	assert(ft_isalpha('$') == 0);    // Special character 
	assert(ft_isalpha('\t') == 0);   // Tab 
	assert(ft_isalpha('\n') == 0);   // Newline 
	assert(ft_isalpha('\0') == 0);   // Null terminator 
	printf("All test cases passed.\n"); 
	return 0; 
} 
*/
