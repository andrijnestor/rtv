/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 20:05:55 by anestor           #+#    #+#             */
/*   Updated: 2018/03/08 22:41:06 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** printing arguments, return value is len of %*** format chars
*/

size_t	ft_print_argument(t_list *list, int argument, int *printf_ret)
{
	size_t	print_len;

	while (list != NULL && ((t_params *)list->content)->argument != argument)
		list = list->next;
	if (list == NULL)
		return (1);
	if (STRUCT(list, type) == 'c')
		ft_print_char(list, printf_ret);
	else if (STRUCT(list, type) == 's' && STRUCT(list, size) != 'l')
		ft_print_string(list, printf_ret);
	else if (STRUCT(list, type) == 's' && STRUCT(list, size) == 'l')
		ft_print_wstring(list, printf_ret);
	else if (STRUCT(list, type) == 'd' || STRUCT(list, type) == 'i')
		ft_print_signed(list, printf_ret);
	else if (STRUCT(list, type) == 'o')
		ft_print_otype(list, printf_ret);
	else if (INTEGER(STRUCT(list, type)))
		ft_print_unsigned(list, printf_ret);
	else if (STRUCT(list, type) == 'p')
	{
		STRUCT(list, flags.hash) = 1;
		STRUCT(list, size) = 'l';
		ft_print_addr(list, printf_ret);
	}
	return (STRUCT(list, print_len));
}

char	*ft_integer_plus_accur(t_list *list)
{
	char	*temp_value;
	char	*ret_value;
	size_t	temp_len;
	size_t	ret_len;

	temp_value = ft_integer_make(STRUCT(list, data),
				STRUCT(list, size), ft_base(list), STRUCT(list, type));
	if (STRUCT(list, type) == 'x' || STRUCT(list, type) == 'p')
		ft_strrmap(temp_value, (char (*)(char))ft_tolower);
	temp_len = ft_strlen(temp_value);
	if (temp_value[0] == '-')
	{
		temp_value = ft_strsub(temp_value, 1, (temp_len - 1));
		temp_len--;
		STRUCT(list, negative) = 1;
	}
	ret_len = BGST(STRUCT(list, accur.num), temp_len);
	ret_value = ft_strnew(ret_len);
	ft_memset(ret_value, '0', ret_len);
	ft_memcpy(ret_value + ret_len - temp_len, temp_value, temp_len);
	return (ft_zero_zero_accur(ret_value, ret_len, list));
}

int		ft_base(t_list *list)
{
	int		base;

	if (STRUCT(list, type) == 'x' || STRUCT(list, type) == 'X')
		base = 16;
	else if (STRUCT(list, type) == 'p')
		base = 16;
	else if (STRUCT(list, type) == 'o' || STRUCT(list, type) == 'O')
		base = 8;
	else
		base = 10;
	return (base);
}

void	ft_set_hash_prefix(char **line, t_list *list)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	while (!ft_isbase(temp[i], 16) && temp[i] != '\0')
		i++;
	if (ft_isbase(temp[i], 16) && i > 1)
	{
		temp[i - 2] = '0';
		temp[i - 1] = 'x';
	}
	else if (i > 1)
	{
		temp[0] = '0';
		temp[1] = 'x';
	}
}

void	ft_set_prefix(char **line, t_list *list)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	while (!ft_isbase(temp[i], 16) && temp[i] != '\0')
		i++;
	if (ft_isbase(temp[i], 16) && i > 0)
	{
		if (STRUCT(list, negative))
			temp[i - 1] = '-';
		else if (STRUCT(list, flags.plus))
			temp[i - 1] = '+';
		else if (STRUCT(list, flags.hash))
		{
			if (STRUCT(list, type) == 'o' || STRUCT(list, type) == 'O')
				temp[i - 1] = '0';
			if ((STRUCT(list, type) == 'X' || STRUCT(list, type) == 'x')
																&& i > 1)
			{
				temp[i - 2] = '0';
				temp[i - 1] = STRUCT(list, type);
			}
		}
	}
}
