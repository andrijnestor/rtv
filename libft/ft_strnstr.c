/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:42:59 by anestor           #+#    #+#             */
/*   Updated: 2017/11/01 18:06:40 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	k;

	k = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[k] != '\0' && k != len)
	{
		n = 0;
		while (haystack[n + k] == needle[n] && haystack[n + k] != '\0' &&
										k + n != len)
			n++;
		if (needle[n] == '\0')
			return ((char *)&haystack[k]);
		k++;
	}
	return (NULL);
}
