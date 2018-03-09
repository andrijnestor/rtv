/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 22:57:59 by anestor           #+#    #+#             */
/*   Updated: 2018/03/09 17:50:39 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_make_matrix(int y, int x)
{
	int		**tmp;
	int		i;

	if (y < 1 || x < 1)
		return (NULL);
	if ((tmp = ft_memalloc(sizeof(int *) * y)) == NULL)
		return (NULL);
	i = 0;
	while (i != y)
	{
		if ((*(tmp + i) = ft_memalloc(sizeof(int) * x)) == NULL)
		{
			ft_memdel((void **)&tmp);
			return (NULL);
		}
		i++;
	}
	return (tmp);
}
