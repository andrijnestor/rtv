/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:44:48 by anestor           #+#    #+#             */
/*   Updated: 2018/03/08 22:41:22 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 32
# define NEXT_LINE ((t_data *)tmp->content)->next_line
# define FD_INDEX ((t_data *)tmp->content)->index
# define SIZE ((t_data *)tmp->content)->size

typedef struct		s_data
{
	int				index;
	size_t			size;
	char			*next_line;
}					t_data;

int					ft_make_line(char **line, t_list **list, int fd);
int					ft_add_temp_line(char *temp, t_list **list, int fd,
																	int size);
char				*ft_strmemjoin(char const *s1, char const *s2, int size,
																int size2);

#endif
