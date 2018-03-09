/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:42:17 by anestor           #+#    #+#             */
/*   Updated: 2017/12/18 16:39:25 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwchar(wchar_t c)
{
	if (c <= 127)
		ft_putchar(c);
	else if (c <= 2047)
	{
		ft_putchar((c >> 6) + 192);
		ft_putchar((c & 63) + 128);
		return (2);
	}
	else if (c <= 65535)
	{
		ft_putchar((c >> 12) + 224);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
		return (3);
	}
	else if (c <= 1114111)
	{
		ft_putchar((c >> 18) + 240);
		ft_putchar(((c >> 12) & 63) + 128);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
		return (4);
	}
	return (1);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	n;

	n = 0;
	while (*str++)
	{
		if (*str <= 127)
			n = n + 1;
		else if (*str <= 2047)
			n = n + 2;
		else if (*str <= 65535)
			n = n + 3;
		else if (*str <= 1114111)
			n = n + 4;
	}
	return (n);
}

void	ft_print_char(t_list *list, int *printf_ret)
{
	if (!STRUCT(list, flags.minus))
		while (STRUCT(list, width.num)-- > 1)
			ft_print_space(printf_ret);
	write(1, &STRUCT(list, data), 1);
	*printf_ret = *printf_ret + 1;
	if (STRUCT(list, flags.minus))
		while (STRUCT(list, width.num)-- > 1)
			ft_print_space(printf_ret);
}

void	ft_print_wstring(t_list *list, int *printf_ret)
{
	wchar_t	*temp;
	size_t	w_len;

	temp = (wchar_t *)STRUCT(list, data);
	if (STRUCT(list, data) == NULL)
	{
		write(1, "(null)", 6);
		*printf_ret = *printf_ret + 6;
		return ;
	}
	w_len = ft_wstrlen(temp);
	if (!STRUCT(list, flags.minus))
		while (STRUCT(list, width.num)-- > (STRUCT(list, accur.star) ?
										STRUCT(list, accur.num) : w_len))
			ft_print_space(printf_ret);
	while ((*temp && !STRUCT(list, accur.star)) ||
					(STRUCT(list, accur.num)-- != 0))
		*printf_ret = *printf_ret + ft_putwchar(*temp++);
	if (STRUCT(list, flags.minus))
		while (STRUCT(list, width.num)-- > 0)
			ft_print_space(printf_ret);
}

void	ft_print_string(t_list *list, int *printf_ret)
{
	size_t	len;
	size_t	print_len;
	size_t	accur;
	char	*print_str;

	if (STRUCT(list, data) == NULL)
	{
		write(1, "(null)", 6);
		*printf_ret = *printf_ret + 6;
		return ;
	}
	len = ft_strlen(STRUCT(list, data));
	if (STRUCT(list, accur.star) && STRUCT(list, accur.num <= len))
		len = STRUCT(list, accur.num);
	print_len = (STRUCT(list, width.num) > len) ? STRUCT(list, width.num) : len;
	print_str = ft_strnew(print_len);
	ft_memset(print_str, ' ', print_len);
	if (STRUCT(list, flags.minus))
		ft_memcpy(print_str, STRUCT(list, data), len);
	else
		ft_memcpy(print_str + print_len - len, STRUCT(list, data), len);
	write(1, print_str, print_len);
	*printf_ret = *printf_ret + print_len;
}
