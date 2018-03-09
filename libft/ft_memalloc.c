/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:25:43 by anestor           #+#    #+#             */
/*   Updated: 2017/11/03 13:31:44 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;
	size_t			n;

	if ((area = (unsigned char *)malloc(size)) == NULL)
		return (NULL);
	n = 0;
	while (n != size)
		area[n++] = 0;
	return (area);
}
