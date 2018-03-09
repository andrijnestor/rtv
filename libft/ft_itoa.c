/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:25:18 by anestor           #+#    #+#             */
/*   Updated: 2017/11/02 13:06:34 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char			*number;
	int				len;
	unsigned long	i;
	long			num;

	len = 1;
	i = 100;
	num = (long)n * 10;
	if (n < 0)
		len++;
	if (n < 0)
		num = (long)n * -10;
	while (num / i > 0)
	{
		i *= 10;
		len++;
	}
	if ((number = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	number[len--] = '\0';
	while (len != -1)
		number[len--] = ((num /= 10) % 10) + 48;
	if (n < 0)
		number[0] = '-';
	return (number);
}
