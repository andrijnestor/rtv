/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:53:12 by anestor           #+#    #+#             */
/*   Updated: 2017/11/07 16:06:08 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_col(char *str, int type, int col)
{
	ft_putstr("\033[");
	ft_putnbr(type);
	ft_putstr(";5;");
	ft_putnbr(col);
	ft_putchar('m');
	ft_putstr(str);
	ft_putstr("\033[0m");
}
