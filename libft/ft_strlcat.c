/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:50:11 by anestor           #+#    #+#             */
/*   Updated: 2017/11/01 15:59:01 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	n;
	size_t	d_size;
	size_t	s_size;

	n = 0;
	s_size = 0;
	while (dst[n] != '\0')
		n++;
	while (src[s_size] != '\0')
		s_size++;
	d_size = n;
	while (*src && n + 1 < dstsize)
		*(dst + n++) = *(src++);
	dst[n] = '\0';
	if (d_size > dstsize)
		return (s_size + dstsize);
	else
		return (s_size + d_size);
}
