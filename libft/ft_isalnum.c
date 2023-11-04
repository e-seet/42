/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:44:38 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 16:44:39 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//alphabets and numeric
//       int isalnum(int c);
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
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
    // Test case 1: Alphanumeric characters (letters and digits) 
    assert(ft_isalnum('A') != 0); 
    assert(ft_isalnum('a') != 0); 
    assert(ft_isalnum('Z') != 0); 
    assert(ft_isalnum('z') != 0); 
    assert(ft_isalnum('0') != 0); 
    assert(ft_isalnum('9') != 0); 

    // Test case 2: Non-alphanumeric characters 
    assert(ft_isalnum(' ') == 0);    // Space 
    assert(ft_isalnum('@') == 0);    // Special character 
    assert(ft_isalnum('$') == 0);    // Special character 
    assert(ft_isalnum('\t') == 0);   // Tab 
    assert(ft_isalnum('\n') == 0);   // Newline 
    assert(ft_isalnum('\0') == 0);   // Null terminator 

    printf("All test cases passed.\n"); 

    return 0; 
} */