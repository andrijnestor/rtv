/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:08:18 by anestor           #+#    #+#             */
/*   Updated: 2017/12/18 16:45:44 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define INTEGER1(x) x == 'd' || x == 'D' || x == 'i' || x == 'u' || x == 'U'
# define INTEGER2(x) x == 'o' || x == 'O' || x == 'x' || x == 'X'
# define INTEGER(x) INTEGER1(x) || INTEGER2(x)
# define FLOAT1(x) x == 'a' || x == 'A' || x == 'e' || x == 'E'
# define FLOAT2(x) x == 'f' || x == 'F' || x == 'g' || x == 'G'
# define FLOAT(x) FLOAT1(x) || FLOAT2(x)
# define CHAR(x) x == 'c' || x == 'C' || x == 's' || x == 'S'
# define POINTER(x) x == 'p' || x == 'n'
# define PERCENT(x) x == '%'
# define OTHER_TYPES(x) CHAR(x) || POINTER(x) || PERCENT(x)
# define ALL_TYPES(x) INTEGER(x) || FLOAT(x) || OTHER_TYPES(x)
# define FLAGS(x) x ==  '+' || x == '-' || x == ' ' || x == '0' || x == '#'
# define SIZE(x) x == 'l' || x == 'h' || x == 'j' || x == 'z' || x == 't'
# define STRUCT(x, y) ((t_params *)(x)->content)->y
# define TRUE(x, y) (x) ? x : y
# define BGST(x, y) (x > y) ? x : y

typedef struct		s_flags
{
	int				space;
	int				plus;
	int				minus;
	int				hash;
	int				zero;
	int				apostr;
}					t_flags;

typedef struct		s_snn
{
	char			star;
	int				num;
}					t_snn;

typedef struct		s_params
{
	struct s_flags	flags;
	void			*data;
	int				argument;
	int				arg_offset;
	int				print_len;
	int				negative;
	struct s_snn	width;
	struct s_snn	accur;
	char			size;
	char			type;
}					t_params;

int					ft_printf(const char *restrict format, ...);
int					ft_printing(t_list *list, const char *format);
size_t				ft_print_argument(t_list *list, int argument,
													int *printf_ret);
void				ft_make_print_line(t_list *list);
void				ft_change_values(t_list **list);

/*
** print nums
*/

char				*ft_integer_make(void *pointer, char size, int base,
																char type);
char				*ft_zero_zero_accur(char *ret_value, size_t ret_len,
															t_list *list);
char				*ft_integer_plus_accur(t_list *list);
int					ft_base(t_list *list);
void				ft_set_hash_prefix(char **line, t_list *list);
void				ft_set_prefix(char **line, t_list *list);
void				ft_print_signed(t_list *list, int *printf_ret);
void				ft_print_unsigned(t_list *list, int *printf_ret);
void				ft_print_addr(t_list *list, int *printf_ret);
void				ft_print_otype(t_list *list, int *printf_ret);

/*
** taking all  params
*/

void				ft_make_params(const char *format, t_list **list,
														va_list ap);
void				ft_make_params_sub(t_list *list, va_list ap, int argument);
int					ft_read_arg_offset(t_list **list, int i,
														const char *format);
int					ft_read_flags(t_list **list, int i, const char *format);
int					ft_read_width(t_list **list, int i, const char *format,
																va_list ap);
int					ft_read_accur(t_list **list, int i, const char *format,
																va_list ap);
int					ft_read_size_n_type(t_list **list, int i, int k,
														const char *format);

/*
** print chars
*/

void				ft_print_space(int *printf_ret);
int					ft_putwchar(wchar_t c);
size_t				ft_wstrlen(wchar_t *str);
void				ft_print_char(t_list *list, int *printf_ret);
void				ft_print_wstring(t_list *list, int *printf_ret);
void				ft_print_string(t_list *list, int *printf_ret);

#endif
