/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:38:10 by eseet             #+#    #+#             */
/*   Updated: 2023/10/05 18:38:11 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// convert hex to int
void	ft_puthex(unsigned int n, int *ptrnum)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, ptrnum);
		if (*ptrnum == -1)
			return ;
	}
	ft_helper(write(1, &"0123456789abcdef"[n % 16], 1), 1, ptrnum);
}
