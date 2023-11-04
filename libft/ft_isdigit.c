/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:15:41 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 17:15:41 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//       int isdigit(int c);
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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

    // Test case 1: Digits 
    assert(ft_isdigit('0') != 0); 
    assert(ft_isdigit('1') != 0); 
    assert(ft_isdigit('9') != 0); 

    // Test case 2: Non-digits 
    assert(ft_isdigit('A') == 0);    // Uppercase letter 
    assert(ft_isdigit('z') == 0);    // Lowercase letter 
    assert(ft_isdigit(' ') == 0);    // Space 
    assert(ft_isdigit('@') == 0);    // Special character 
    assert(ft_isdigit('\t') == 0);   // Tab 
    assert(ft_isdigit('\n') == 0);   // Newline 
    assert(ft_isdigit('\0') == 0);   // Null terminator 

    printf("All test cases passed.\n"); 
    return 0; 
} */