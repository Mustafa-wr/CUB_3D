/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:49:30 by bammar            #+#    #+#             */
/*   Updated: 2023/04/16 18:17:43 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					k;
	unsigned long long	value;
	int					d;

	i = 0;
	k = 1;
	d = 0;
	value = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
			i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			k = k * -1;
	while (str[i] == '0')
			i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i++] - 48);
		d++;
	}
	if (d > 19 || value >= 9223372036854775808ULL)
		return (-(k == 1));
	return (value * k);
}
