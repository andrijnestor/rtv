/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:28:08 by anestor           #+#    #+#             */
/*   Updated: 2017/11/02 10:51:35 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	if ((temp = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strcat(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}
