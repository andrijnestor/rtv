/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:29:50 by anestor           #+#    #+#             */
/*   Updated: 2017/12/18 16:26:05 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_read_arg_offset(t_list **list, int i, const char *format)
{
	int		k;

	k = i;
	while (ft_isdigit(format[k]))
		k++;
	if (format[k] == '$')
	{
		STRUCT(*list, arg_offset) = ft_atoi(&format[i]);
		k++;
		return (k);
	}
	return (i);
}

int		ft_read_flags(t_list **list, int i, const char *format)
{
	while (FLAGS(format[i]))
	{
		if (format[i] == '+')
			STRUCT(*list, flags.plus) = 1;
		else if (format[i] == '-')
			STRUCT(*list, flags.minus) = 1;
		else if (format[i] == ' ')
			STRUCT(*list, flags.space) = 1;
		else if (format[i] == '#')
			STRUCT(*list, flags.hash) = 1;
		else if (format[i] == '0')
			STRUCT(*list, flags.zero) = 1;
		else if (format[i] == '`')
			STRUCT(*list, flags.apostr) = 1;
		i++;
	}
	return (i);
}

int		ft_read_width(t_list **list, int i, const char *format, va_list ap)
{
	if (format[i] == '*')
	{
		STRUCT(*list, width.star) = '*';
		STRUCT(*list, width.num) = va_arg(ap, int);
		i++;
	}
	else
	{
		STRUCT(*list, width.star) = 1;
		STRUCT(*list, width.num) = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	return (i);
}

int		ft_read_accur(t_list **list, int i, const char *format, va_list ap)
{
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			STRUCT(*list, accur.star) = '*';
			STRUCT(*list, accur.num) = va_arg(ap, int);
			i++;
		}
		else
		{
			STRUCT(*list, accur.star) = 1;
			STRUCT(*list, accur.num) = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
		}
	}
	return (i);
}

int		ft_read_size_n_type(t_list **list, int i, int k, const char *format)
{
	if (format[i] == 'l' && format[i + 1] == 'l')
	{
		STRUCT(*list, size) = 'w';
		i = i + 2;
	}
	else if (format[i] == 'h' && format[i + 1] == 'h')
	{
		STRUCT(*list, size) = 'm';
		i = i + 2;
	}
	else if (SIZE(format[i]))
	{
		STRUCT(*list, size) = format[i];
		i++;
	}
	if (ALL_TYPES(format[i]))
	{
		STRUCT(*list, type) = format[i];
		i++;
	}
	STRUCT(*list, print_len) = i - k;
	return (i);
}
