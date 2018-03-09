/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:40:43 by anestor           #+#    #+#             */
/*   Updated: 2017/10/29 15:09:16 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned long	*dest;
	unsigned long	*sorc;
	unsigned char	*d;
	unsigned char	*s;
	size_t			size;

	dest = (unsigned long *)dst;
	sorc = (unsigned long *)src;
	size = n / sizeof(unsigned long);
	n = n - size * sizeof(unsigned long);
	while (size--)
		*dest++ = *sorc++;
	d = (unsigned char *)dest;
	s = (unsigned char *)sorc;
	while (n--)
		*d++ = *s++;
	return (dst);
}
