/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:31:54 by anestor           #+#    #+#             */
/*   Updated: 2017/12/06 20:55:59 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	int		n;

	if (s && f)
	{
		if ((temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
			return (NULL);
		n = 0;
		while (s[n] != '\0')
		{
			temp[n] = (*f)(n, s[n]);
			n++;
		}
		temp[n] = '\0';
		return (temp);
	}
	return (NULL);
}
