/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:23:18 by anestor           #+#    #+#             */
/*   Updated: 2017/11/01 16:46:15 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				k;
	int long long	num;

	num = n;
	k = 1000000000;
	if (num < 0)
	{
		num = num * -1;
		ft_putchar_fd('-', fd);
	}
	if (num == 0 || num == 1)
		ft_putchar_fd('0' + num, fd);
	else
	{
		while (num < k)
			k /= 10;
		while (k != 0)
		{
			(num != 0) ? (ft_putchar_fd((num / k) + '0', fd)) :
				(ft_putchar_fd('0', fd));
			num = num - (num / k) * k;
			k /= 10;
		}
	}
}
