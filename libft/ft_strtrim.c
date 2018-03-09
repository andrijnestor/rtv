/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:01:58 by anestor           #+#    #+#             */
/*   Updated: 2017/11/01 15:49:27 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*temp;
	size_t	len;
	int		n;
	int		k;

	n = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[n] == ' ' || s[n] == '\n' || s[n] == '\t')
	{
		len++;
		n++;
	}
	k = ft_strlen(s) - 1;
	while (k >= 0 && (s[k] == ' ' || s[k] == '\n' || s[k] == '\t'))
	{
		len++;
		k--;
	}
	len = ((n == (int)ft_strlen(s)) ? 0 : ft_strlen(s) - len);
	if ((temp = ft_strsub(s, n, len)) == NULL)
		return (NULL);
	return (temp);
}
