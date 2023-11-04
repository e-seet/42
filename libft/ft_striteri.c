/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:33:49 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 18:33:50 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//para
// s: The string on which to iterate.
// f: The function to apply to each character

// Applies the function ’f’ on each character of
// the string passed as argument, passing its index
// as first argument. Each character is passed by
// address to ’f’ to be modified if necessary.
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s == NULL)
		return ((void) NULL);
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void uppercase_modifier(unsigned int index, char *c) {
//     if (*c >= 'a' && *c <= 'z')
//     {
//         // Convert to uppercase
//         *c = *c - 'a' + 'A';
//     }
// }

// int main() {
//     // Test Case 1: Modify characters to uppercase
//     char input1[] = "Hello, World!";
//     ft_striteri(input1, uppercase_modifier);

//     printf("Test Case 1: Modified String 1: %s\n", input1);

//     // Test Case 2: NULL input string
//     char *input2 = NULL;
//     ft_striteri(input2, uppercase_modifier);
//      // Should handle NULL input gracefully

//     printf("Test Case 2: Modified NULL input string.\n");

//     return 0;
// }
