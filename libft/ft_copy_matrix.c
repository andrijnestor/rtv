/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:25:00 by anestor           #+#    #+#             */
/*   Updated: 2018/03/08 23:25:09 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_copy_matrix(int **src, t_xy s, t_xy e)
{
	int		**dst;
	t_xy	i;

	if (s.x < 0 || s.y < 0 || e.y < 0 || e.x < 0 || e.x < s.x || e.y < s.y)
		return (NULL);
	if ((dst = ft_memalloc(sizeof(int *) * (e.y - s.y + 1))) == NULL)
		return (NULL);
	i.y = 0;
	while (i.y + s.y != e.y + 1)
	{
		if ((dst[i.y] = ft_memalloc(sizeof(int) * (e.x - s.x + 1))) == NULL)
		{
			ft_memdel((void **)&dst);
			return (NULL);
		}
		i.x = 0;
		while (i.x + s.x != e.x + 1)
		{
			dst[i.y][i.x] = src[i.y + s.y][i.x + s.x];
			i.x++;
		}
		i.y++;
	}
	return (dst);
}
