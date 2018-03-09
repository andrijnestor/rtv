/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:28:58 by anestor           #+#    #+#             */
/*   Updated: 2018/01/24 12:32:33 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			*temp;
	int				ret;

	if (line == NULL)
		return (-1);
	if ((temp = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	while ((ret = read(fd, temp, BUFF_SIZE)) > 0)
	{
		if (ft_add_temp_line(temp, &list, fd, ret) == 1)
			break ;
		ft_bzero(temp, BUFF_SIZE);
	}
	ft_memdel((void **)&temp);
	if (ret == -1)
		return (-1);
	return (ft_make_line(line, &list, fd));
}

int		ft_make_line(char **line, t_list **list, int fd)
{
	size_t	i;
	char	*line_temp;
	t_list	*tmp;

	tmp = *list;
	i = 0;
	while (tmp != NULL && FD_INDEX != fd)
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	if (!NEXT_LINE || SIZE < 1)
		return (0);
	while (NEXT_LINE[i] != '\n' && i != SIZE)
		i++;
	*line = ft_strsub(NEXT_LINE, 0, i);
	if (i == SIZE)
		ft_memdel((void **)&NEXT_LINE);
	else
	{
		line_temp = ft_strsub(NEXT_LINE, i + 1, SIZE -= (i + 1));
		ft_memdel((void **)&NEXT_LINE);
		NEXT_LINE = ft_strsub(line_temp, 0, SIZE);
		ft_memdel((void **)&line_temp);
	}
	return (1);
}

int		ft_add_temp_line(char *temp, t_list **list, int fd, int size)
{
	t_list	*tmp;
	char	*line_temp;
	t_data	*data;

	tmp = *list;
	while (tmp != NULL && FD_INDEX != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
			return (1);
		if ((tmp = ft_lstnew(data, sizeof(t_data))) == NULL)
			return (1);
		FD_INDEX = fd;
		SIZE = size;
		NEXT_LINE = ft_strsub(temp, 0, size);
		ft_lstadd(list, tmp);
		ft_memdel((void **)&data);
		return ((ft_memchr(NEXT_LINE, '\n', SIZE)) ? (1) : (0));
	}
	line_temp = ft_strsub(NEXT_LINE, 0, SIZE);
	ft_memdel((void **)&NEXT_LINE);
	NEXT_LINE = ft_strmemjoin(line_temp, temp, SIZE, size);
	ft_memdel((void **)&line_temp);
	return ((ft_memchr(NEXT_LINE, '\n', SIZE = SIZE + size)) ? (1) : (0));
}

char	*ft_strmemjoin(char const *s1, char const *s2, int size, int size2)
{
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	if ((temp = ft_strnew(size + size2)) == NULL)
		return (NULL);
	ft_memcpy(temp, s1, size);
	temp = temp + size;
	ft_memcpy(temp, s2, size2);
	return (temp - size);
}
