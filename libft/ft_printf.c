/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:23:46 by anestor           #+#    #+#             */
/*   Updated: 2017/12/18 16:16:51 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** main printing function, call ft_print_argument for printing arguments
*/

int		ft_printing(t_list *list, const char *format)
{
	int		argument;
	size_t	len;
	size_t	format_len;
	int		printf_ret;

	argument = 0;
	len = 0;
	printf_ret = 0;
	format_len = ft_strlen(format);
	while (len < format_len)
	{
		if (format[len] != '%' && format[len])
		{
			write(1, &format[len], 1);
			len++;
			printf_ret++;
		}
		else
		{
			len = len + ft_print_argument(list, argument, &printf_ret);
			argument++;
		}
	}
	return (printf_ret);
}

/*
** taking all parameters
*/

void	ft_make_params_sub(t_list *list, va_list ap, int argument)
{
	STRUCT(list, argument) = argument++;
	if (STRUCT(list, type) == 0)
	{
		STRUCT(list, data) = "";
		STRUCT(list, type) = 's';
	}
	else if (STRUCT(list, type) == '%')
	{
		STRUCT(list, accur.star) = 0;
		STRUCT(list, data) = "%";
		STRUCT(list, type) = 's';
	}
	else
		STRUCT(list, data) = va_arg(ap, void *);
}

void	ft_make_params(const char *format, t_list **list, va_list ap)
{
	int			argument;
	t_params	*info;
	int			i;
	int			k;

	argument = 0;
	i = -1;
	while (format[++i])
		if (format[i] == '%')
		{
			info = (t_params *)ft_memalloc(sizeof(t_params));
			k = i++;
			if (list)
				ft_lstadd(list, ft_lstnew(info, sizeof(t_params)));
			else
				*list = ft_lstnew(info, sizeof(t_params));
			ft_memdel((void **)&info);
			i = ft_read_arg_offset(list, i, format);
			i = ft_read_flags(list, i, format);
			i = ft_read_width(list, i, format, ap);
			i = ft_read_accur(list, i, format, ap);
			i = ft_read_size_n_type(list, i, k, format);
			i--;
			ft_make_params_sub(*list, ap, argument++);
		}
}

/*
** convert uppercase type to lowercase + size l
*/

void	ft_change_values(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp != NULL)
	{
		if (STRUCT(temp, type) == 'D' || STRUCT(temp, type) == 'O' ||
			STRUCT(temp, type) == 'U' || STRUCT(temp, type) == 'S' ||
			STRUCT(temp, type) == 'C')
		{
			STRUCT(temp, type) = STRUCT(temp, type) + 32;
			STRUCT(temp, size) = 'l';
		}
		temp = temp->next;
	}
}

/*
** main function
*/

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_list		*list;

	list = NULL;
	va_start(ap, format);
	ft_make_params(format, &list, ap);
	va_end(ap);
	ft_change_values(&list);
	return (ft_printing(list, format));
}
