/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:04:12 by anestor           #+#    #+#             */
/*   Updated: 2017/12/12 16:07:32 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long int number, int base)
{
	unsigned long long int	num;
	int						len;
	char					*numbase;

	len = 1;
	if (base < 2 || base > 16)
		return (NULL);
	(number < 0) ? (len++) : (0);
	num = ((number < 0) ? (number * -1) : (number));
	while (num >= base)
	{
		len++;
		num = num / base;
	}
	num = ((number < 0) ? (number * -1) : (number));
	if ((numbase = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- != -1)
	{
		numbase[len] = num % base + ((num % base > 9) ? ('7') : ('0'));
		num = num / base;
	}
	if (number < 0)
		numbase[0] = '-';
	return (numbase);
}
