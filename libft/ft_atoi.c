/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:08:19 by anestor           #+#    #+#             */
/*   Updated: 2017/11/01 19:17:35 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				n;
	long long int	number;
	long long int	neg;

	n = 0;
	neg = 1;
	number = 0;
	while (str[n] == 32 || str[n] == 9 || str[n] == 10 ||
			str[n] == 11 || str[n] == 12 || str[n] == 13)
		n++;
	if (str[n] == '+' || str[n] == '-')
		if (str[n++] == '-')
			neg = -1;
	while (str[n] != '\0' && str[n] > 47 && str[n] < 58)
	{
		if (number >= 922337203685477581)
			return (neg < 0 ? 0 : -1);
		number = (number * 10) + (long long int)(str[n++] - 48);
	}
	return (number * neg);
}
