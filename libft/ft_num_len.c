/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:22:34 by anestor           #+#    #+#             */
/*   Updated: 2018/01/13 19:30:43 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_len(long long int num)
{
	int		count;

	count = 0;
	if (num < 0)
	{
		num = num * -1;
		count++;
	}
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	if (num >= 0 && num < 10)
	{
		count++;
	}
	return (count);
}
