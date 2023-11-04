/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:07:26 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 17:07:27 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//parameter
// n: the integer to convert

//return
// The string representing the integer.
// NULL if the allocation fails
#include "libft.h"

char	*reverse(char *str, int i)
{
	int		j;
	char	temp;

	j = 0;
	if (str[0] == '-')
		j = 1;
	while (i > j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

int	charsize(int n)
{
	int	num;

	num = 0;
	if (n < 0 && n != -2147483648)
	{
		num = num + 1;
		n = n * -1;
	}
	else if (n == -2147483648)
	{
		return (11);
	}
	while (n >= 10)
	{
		n = n / 10;
		num++;
	}
	return (num + 1);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	n2;

	str = malloc(sizeof(char) * (charsize(n) + 1));
	if (!str)
		return (0);
	ft_bzero(str, charsize(n) + 1);
	n2 = n;
	i = 0;
	if (0 > n2)
	{
		str[i] = '-';
		n2 = n2 * -1;
		i = 1;
	}
	while (n2 > 9)
	{
		str[i] = n2 % 10 + '0';
		n2 = n2 / 10;
		i++;
	}
	str[i] = n2 + '0';
	str[i + 1] = '\0';
	return (reverse(str, i));
}

/*

int main() {
    // Test Case 1: Positive integer
    int num1 = 12345;
    char *str1 = ft_itoa(num1);

    if (str1 != NULL) {
        printf("Test Case 1: Integer %d as a string: %s\n", num1, str1);
    } else {
        printf("Memory allocation failed for Test Case 1!\n");
    }

    // Test Case 2: Negative integer
    int num2 = -6789;
    char *str2 = ft_itoa(num2);

    if (str2 != NULL) {
        printf("Test Case 2: Integer %d as a string: %s\n", num2, str2);
    } else {
        printf("Memory allocation failed for Test Case 2!\n");
    }

    // Test Case 3: Zero
    int num3 = 0;
    char *str3 = ft_itoa(num3);

    if (str3 != NULL) {
        printf("Test Case 3: Integer %d as a string: %s\n", num3, str3);
    } else {
        printf("Memory allocation failed for Test Case 3!\n");
    }

    return 0;
}
*/