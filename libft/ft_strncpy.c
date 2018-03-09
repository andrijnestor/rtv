/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:57:12 by anestor           #+#    #+#             */
/*   Updated: 2017/10/31 17:41:59 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	n;

	n = 0;
	while (n != len && src[n] != '\0')
	{
		dst[n] = src[n];
		n++;
	}
	while (n != len)
	{
		dst[n] = '\0';
		n++;
	}
	return (dst);
}
