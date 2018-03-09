/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:59:26 by anestor           #+#    #+#             */
/*   Updated: 2017/10/28 16:30:30 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(s1) + 1;
	if ((tmp = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, len);
	return (tmp);
}
