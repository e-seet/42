/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:20:21 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 17:20:22 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//       int isprint(int c);
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	// Test case 1: Printable characters 
	assert(ft_isprint('A') != 0);   // Uppercase letter 
	assert(ft_isprint('a') != 0);   // Lowercase letter 
	assert(ft_isprint('0') != 0);   // Digit 
	assert(ft_isprint(' ') != 0);   // Space 
	assert(ft_isprint('!') != 0);   // Special character 
	assert(ft_isprint('.') != 0);   // Special character 

	// Test case 2: Non-printable characters 
	assert(ft_isprint('\t') == 0);  // Tab 
	assert(ft_isprint('\n') == 0);  // Newline 
	assert(ft_isprint('\b') == 0);  // Backspace 
	assert(ft_isprint('\x7F') == 0); // DEL (delete) character 

	printf("All test cases passed.\n"); 
	return 0; 
} */