/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:54:25 by anestor           #+#    #+#             */
/*   Updated: 2017/10/31 21:15:58 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t	i;
	size_t	size;
	size_t	j;

	i = ft_strlen(s1);
	size = i + ft_strlen(s2);
	j = 0;
	while (i != size)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
