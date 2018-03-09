/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:07:34 by anestor           #+#    #+#             */
/*   Updated: 2017/11/02 15:29:04 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int str_base)
{
	long long int	num;
	int				neg;

	neg = 1;
	if (str_base < 2 || str_base > 16)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	num = 0;
	while (ft_isbase(*str, str_base))
		if (*str < 'A')
			num = (num * str_base) + (*str++ - '0');
		else
			num = (num * str_base) + (*str++ - '@' + str_base % 10);
	return (num * neg);
}
