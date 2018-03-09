/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 22:53:43 by anestor           #+#    #+#             */
/*   Updated: 2018/03/08 22:57:32 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_make_array(int size)
{
	int		*arr;

	if (size < 1)
		return (NULL);
	if ((arr = ft_memalloc(sizeof(int) * size)) == NULL)
		return (NULL);
	return (arr);
}
