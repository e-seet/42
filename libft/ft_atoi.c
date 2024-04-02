/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:56:48 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 13:56:50 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Write a function that converts the initial portion of the 
// string pointed by str to its int representation

// The string can start with an arbitray amount of white space 
// (as determined by isspace(3))

// The string can be followed by an arbitrary amount of
// + and - signs, - sign will change the sign of the int
// returned based on the number of - is odd or even.

// Finally the string can be followed by any numbers of base 10.

// Your function should read the string until the string
// stop following the rules and return the number found until now.

//       int atoi(const char *nptr);
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = str[i] - 48 + num * 10;
		i++;
	}
	return (num * sign);
}

/*
*/
// int	main()
// { 
	// Test case 1: Basic positive integer 
	// char *str1 = "12345"; 
	// int result1 = ft_atoi(str1); 
	// assert(result1 == 12345); 

	// Test case 2: Basic negative integer 
	// char *str2 = "-6789"; 
	// int result2 = ft_atoi(str2);
	// printf("%d\n", result2);
	// assert(result2 == -6789); 

	// Test case 3: Leading and trailing whitespaces 
	// char *str3 = "   42  "; 
	// int result3 = ft_atoi(str3); 
	// printf("%d\n", result3);
	// assert(result3 == 42); 

	// // Test case 4: Non-numeric characters after valid integer 
	// char *str4 = "123abc"; 
	// int result4 = ft_atoi(str4); 
	// printf("%d\n", result4);
	// assert(result4 == 123); 

	// // Test case 5: Empty string 
	// char *str5 = ""; 
	// int result5 = ft_atoi(str5); 
	// printf("%d\n", result5);
	// assert(result5 == 0); 
	// Expected behavior is undefined; may vary by implementation 

	// // Test case 6: String starting with non-numeric characters 
	// char *str6 = "abc123"; 
	// int result6 = ft_atoi(str6);
	// printf("%d\n", result6); 
	// assert(result6 == 0); 
	// Expected behavior is undefined; may vary by implementation 

	// Test case 7: Overflow [To check]
	// char *str7 = "2147483648"; // One more than INT_MAX on many systems 
	// int result7 = ft_atoi(str7); 
	// printf("%d\n", result7); 
	// assert(result7 == INT_MAX); 
	// Expected behavior is undefined; may vary by implementation 

	// // Test case 8: Underflow  [To check]
	// char *str8 = "-2147483649"; // One less than INT_MIN on many systems 
	// int result8 = ft_atoi(str8); 
	// assert(result8 == INT_MIN); 
	// Expected behavior is undefined; may vary by implementation 
//     return 0; 
// } 