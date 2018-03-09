/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:17:19 by anestor           #+#    #+#             */
/*   Updated: 2017/11/02 12:19:48 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (s < d && d < s + len)
	{
		s = s + len;
		d = d + len;
		while (len--)
			*(--d) = *(--s);
	}
	else
	{
		while (len--)
			*(d++) = *(s++);
	}
	return (dst);
}
