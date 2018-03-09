/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_kostyl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:24:36 by anestor           #+#    #+#             */
/*   Updated: 2017/12/18 16:18:47 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero_zero_accur(char *ret_value, size_t ret_len, t_list *list)
{
	if (STRUCT(list, accur.star) && STRUCT(list, accur.num) == 0
						&& ret_len == 1 && ret_value[0] == '0')
	{
		ret_value = ft_strnew(0);
	}
	return (ret_value);
}

void	ft_print_space(int *printf_ret)
{
	write(1, " ", 1);
	*printf_ret = *printf_ret + 1;
}
