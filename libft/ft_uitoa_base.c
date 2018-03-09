/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:45:04 by anestor           #+#    #+#             */
/*   Updated: 2017/12/12 16:45:21 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned long long int number, int base)
{
	unsigned long long int	num;
	int						len;
	char					*numbase;

	len = 1;
	if (base < 2 || base > 16)
		return (NULL);
	num = number;
	while (num >= base)
	{
		len++;
		num = num / base;
	}
	num = number;
	if ((numbase = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- != -1)
	{
		numbase[len] = num % base + ((num % base > 9) ? ('7') : ('0'));
		num = num / base;
	}
	return (numbase);
}
