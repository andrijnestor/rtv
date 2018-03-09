/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:17:22 by anestor           #+#    #+#             */
/*   Updated: 2017/11/28 16:11:20 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s)
	{
		if ((substr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ft_memcpy(substr, &s[start], len);
		substr[len] = '\0';
		return (substr);
	}
	return (NULL);
}
