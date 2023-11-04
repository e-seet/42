/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:07:55 by eseet             #+#    #+#             */
/*   Updated: 2023/09/06 17:07:56 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//       int isascii(int c);
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	int ch1 = 68;    // An ASCII character 
	int ch2 = 500;    // A non-ASCII character (copyright symbol) 

	if (ft_isascii(ch1))
	{ 
		printf("%c is an ASCII character.\n", ch1); 
	}
	else
	{ 
		printf("%c is not an ASCII character.\n", ch1); 
	} 

	if (ft_isascii(ch2))
	{ 
		printf("%c is an ASCII character.\n", ch2); 
	}
	else
	{ 
		printf("%c is not an ASCII character.\n", ch2); 
	} 
	return 0; 
}*/
