/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:38:18 by eseet             #+#    #+#             */
/*   Updated: 2023/10/05 18:38:19 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
// treat the memory address stored in p as an unsigned integer.
uintptr_t x = (uintptr_t)p;

buf[i + 2] = "0123456789abcdef"[(x >> ((sizeof(x) * 8 - 4 - i * 4)) & 0xf)];
void more_stuff(uint32_t value) {     
// Example value: 0x01020304

uint32_t byte1 = (value >> 24);           
// 0x01020304 >> 24 is 0x01 so no masking is necessary

uint32_t byte2 = (value >> 16) & 0xff;    
// 0x01020304 >> 16 is 0x0102 so we must mask to get 0x02

uint32_t byte3 = (value >> 8)  & 0xff;    
// 0x01020304 >> 8 is 0x010203 so we must mask to get 0x03
uint32_t byte4 = value & 0xff;            
// here we only mask, no shiftingis necessary
}
*/
#include "libft.h"

int	ft_putptrhelper(char *buf, uintptr_t x)
{
	size_t		i;
	size_t		startindex;

	i = 0;
	startindex = 2;
	buf[0] = '0';
	buf[1] = 'x';
	while (sizeof(x) * 2 > i)
	{
		buf[i + 2] = "0123456789abcdef"
		[(x >> ((sizeof(x) * 8 - 4 - i * 4)) & 0xf)];
		i++;
	}
	while (buf[startindex] == '0')
		startindex++;
	return (startindex);
}

// print address of the pointer

// the following line is applicable for macos.
// ft_helper(write(1, "0x0", 3), 3, ptrnum);
// however in ubuntu, you need to write (nil) instead
// which is 5 characters
void	ft_putptr(void *s, int *ptrnum)
{
	char		buf[2 + sizeof((uintptr_t)s) * 2];
	size_t		startindex;
	size_t		length;
	uintptr_t	x;

	x = (uintptr_t) s;
	if (x == 0)
	{
		ft_helper(write(1, "(nil)", 5), 5, ptrnum);
		return ;
	}
	startindex = ft_putptrhelper(buf, x);
	length = 2 + sizeof(x) * 2 - startindex;
	ft_helper(write(1, buf, 2), 2, ptrnum);
	if (*ptrnum != -1)
		ft_helper(write(1, buf + startindex, length), length, ptrnum);
}
