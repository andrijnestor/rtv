/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:38:48 by anestor           #+#    #+#             */
/*   Updated: 2017/11/10 13:39:06 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		divid;
	int		result;

	divid = 1;
	result = 0;
	while (nb > 0)
	{
		nb = nb - divid;
		divid = divid + 2;
		if (nb < 0)
			result = result + 0;
		else
			result = result + 1;
	}
	if (nb >= 0)
		return (result);
	else
		return (0);
}
