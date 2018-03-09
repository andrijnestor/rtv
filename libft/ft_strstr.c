/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:36:21 by anestor           #+#    #+#             */
/*   Updated: 2017/10/31 22:45:40 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		n = 0;
		while (haystack[n] == needle[n] && haystack[n] != '\0')
			n++;
		if (needle[n] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
