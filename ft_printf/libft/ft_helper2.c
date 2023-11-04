/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:38:03 by eseet             #+#    #+#             */
/*   Updated: 2023/10/05 18:38:03 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_helper(size_t write_ok, size_t size, int *ptrnum)
{
	if (write_ok != size)
	{
		*ptrnum = -1;
		return ;
	}
	*ptrnum = *ptrnum + (int) size;
}
