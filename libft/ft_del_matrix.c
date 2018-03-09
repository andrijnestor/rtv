/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:05:36 by anestor           #+#    #+#             */
/*   Updated: 2018/03/08 23:08:53 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_matrix(int **arr, int y)
{
	int		i;

	i = 0;
	while (i != y)
	{
		ft_memdel((void **)&arr[i]);
		i++;
	}
	ft_memdel((void **)&arr);
}
