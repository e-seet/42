/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:17:34 by eseet             #+#    #+#             */
/*   Updated: 2024/04/08 17:17:35 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// math math
void	parseinteger(char *str, int *i, int *neg, double *value)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg = *neg * -1;
		(*i)++;
	}
	while (str[*i] != '.' && (str[*i] >= '0' && str[*i] <= '9'))
	{
		*value = *value * 10 + (str[*i] - '0');
		(*i)++;
	}
}

double	returndouble(char *str)
{
	double	value;
	int		i;
	int		neg;
	double	tenth;

	value = 0;
	i = 0;
	neg = 1;
	tenth = 1;
	parseinteger(str, &i, &neg, &value);
	if (str[i] == '.')
		i++;
	while (str[i] != '.' && (str[i] >= '0' && str[i] <= '9'))
	{
		tenth = tenth / 10;
		value = value + ((str[i] - '0') * (tenth));
		i++;
	}
	return (value * neg);
}

double	scale(double unscaled_num, double new_min, double new_max,
	double old_max)
{
	double	old_min;
	double	newscale;
	double	oldscale;
	double	number;

	old_min = 0;
	newscale = new_max - new_min;
	oldscale = old_max - old_min;
	number = unscaled_num - old_min;
	return ((newscale * (number / oldscale)) + new_min);
}

t_complex_num	square_complex(t_complex_num z)
{
	t_complex_num	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex_num	sum_complex(t_complex_num z1, t_complex_num z2)
{
	t_complex_num	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}
