/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:56:37 by anestor           #+#    #+#             */
/*   Updated: 2017/12/18 16:17:32 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_signed(t_list *list, int *printf_ret)
{
	char	*temp_value;
	char	*print_line;
	size_t	temp_len;
	size_t	print_len;
	int		offset;

	temp_value = ft_integer_plus_accur(list);
	temp_len = ft_strlen(temp_value);
	offset = TRUE(STRUCT(list, negative), TRUE(STRUCT(list, flags.plus),
											STRUCT(list, flags.space)));
	print_len = BGST(STRUCT(list, width.num), temp_len + offset);
	print_line = ft_strnew(print_len);
	ft_memset(print_line, ' ', print_len);
	if (STRUCT(list, flags.zero) && !STRUCT(list, accur.num) &&
											!STRUCT(list, flags.minus))
		ft_memset(print_line + offset, '0', print_len - offset);
	if (STRUCT(list, flags.minus))
		ft_memcpy(print_line + offset, temp_value, temp_len);
	else
		ft_memcpy(print_line + print_len - temp_len, temp_value, temp_len);
	ft_set_prefix(&print_line, list);
	write(1, print_line, print_len);
	*printf_ret = *printf_ret + print_len;
}

void	ft_print_unsigned(t_list *list, int *printf_ret)
{
	char	*temp_value;
	char	*print_line;
	size_t	temp_len;
	size_t	print_len;
	int		offset;

	temp_value = ft_integer_plus_accur(list);
	temp_len = ft_strlen(temp_value);
	offset = 0;
	if (STRUCT(list, flags.hash) && temp_len > 1)
		offset = ft_base(list) / 8;
	print_len = BGST(STRUCT(list, width.num), temp_len + offset);
	print_line = ft_strnew(print_len);
	ft_memset(print_line, ' ', print_len);
	if (STRUCT(list, flags.zero) && !STRUCT(list, accur.num) &&
											!STRUCT(list, flags.minus))
		ft_memset(print_line + offset, '0', print_len - offset);
	if (STRUCT(list, flags.minus))
		ft_memcpy(print_line + offset, temp_value, temp_len);
	else
		ft_memcpy(print_line + print_len - temp_len, temp_value, temp_len);
	ft_set_prefix(&print_line, list);
	write(1, print_line, print_len);
	*printf_ret = *printf_ret + print_len;
}

void	ft_print_otype(t_list *list, int *printf_ret)
{
	char	*temp_value;
	char	*print_line;
	size_t	temp_len;
	size_t	print_len;
	int		offset;

	temp_value = ft_integer_plus_accur(list);
	temp_len = ft_strlen(temp_value);
	offset = 0;
	if (STRUCT(list, flags.hash) && temp_value[0] != '0')
		offset = ft_base(list) / 8;
	print_len = BGST(STRUCT(list, width.num), temp_len + offset);
	print_line = ft_strnew(print_len);
	ft_memset(print_line, ' ', print_len);
	if (STRUCT(list, flags.zero) && !STRUCT(list, accur.num) &&
											!STRUCT(list, flags.minus))
		ft_memset(print_line + offset, '0', print_len - offset);
	if (STRUCT(list, flags.minus))
		ft_memcpy(print_line + offset, temp_value, temp_len);
	else
		ft_memcpy(print_line + print_len - temp_len, temp_value, temp_len);
	(print_len == 1 && STRUCT(list, flags.hash)) ? print_line[0] = '0' :
										ft_set_prefix(&print_line, list);
	write(1, print_line, print_len);
	*printf_ret = *printf_ret + print_len;
}

void	ft_print_addr(t_list *list, int *printf_ret)
{
	char	*temp_value;
	char	*print_line;
	size_t	temp_len;
	size_t	print_len;
	int		offset;

	temp_value = ft_integer_plus_accur(list);
	temp_len = ft_strlen(temp_value);
	offset = 2;
	print_len = BGST(STRUCT(list, width.num), temp_len + offset);
	print_line = ft_strnew(print_len);
	ft_memset(print_line, ' ', print_len);
	if (STRUCT(list, flags.zero) && !STRUCT(list, accur.num) &&
											!STRUCT(list, flags.minus))
		ft_memset(print_line + offset, '0', print_len - offset);
	if (STRUCT(list, flags.minus))
		ft_memcpy(print_line + offset, temp_value, temp_len);
	else
		ft_memcpy(print_line + print_len - temp_len, temp_value, temp_len);
	ft_set_hash_prefix(&print_line, list);
	write(1, print_line, print_len);
	*printf_ret = *printf_ret + print_len;
}

char	*ft_integer_make(void *pointer, char size, int base, char type)
{
	char	*temp;

	if (size == 'm')
		(type == 'd' || type == 'i') ? (temp = ft_itoa_base((char)pointer,
		base)) : (temp = ft_uitoa_base((unsigned char)pointer, base));
	else if (size == 'w')
		(type == 'd' || type == 'i') ? (temp = ft_itoa_base((long int)pointer,
		base)) : (temp = ft_uitoa_base((unsigned long int)pointer, base));
	else if (size == 'l')
		(type == 'd' || type == 'i') ?
			(temp = ft_itoa_base((long long int)pointer, base)) :
			(temp = ft_uitoa_base((unsigned long long int)pointer, base));
	else if (size == 'h')
		(type == 'd' || type == 'i') ? (temp = ft_itoa_base((short int)pointer,
		base)) : (temp = ft_uitoa_base((unsigned short int)pointer, base));
	else if (size == 'j')
		(type == 'd' || type == 'i') ? (temp = ft_itoa_base((intmax_t)pointer,
		base)) : (temp = ft_uitoa_base((uintmax_t)pointer, base));
	else if (size == 'z' || size == 't')
		(type == 'd' || type == 'i') ? (temp = ft_itoa_base((ssize_t)pointer,
		base)) : (temp = ft_uitoa_base((size_t)pointer, base));
	else
		(type == 'd' || type == 'i') ? (temp = ft_itoa_base((int)pointer,
		base)) : (temp = ft_uitoa_base((unsigned int)pointer, base));
	return (temp);
}
