/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:51:10 by anestor           #+#    #+#             */
/*   Updated: 2017/11/06 12:57:02 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_char(char const *s, char c)
{
	char	*temp;
	size_t	len;
	int		n;
	int		k;

	n = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[n] == c || s[n] == '\n' || s[n] == '\t')
	{
		len++;
		n++;
	}
	k = ft_strlen(s) - 1;
	while (k >= 0 && (s[k] == c || s[k] == '\n' || s[k] == '\t'))
	{
		len++;
		k--;
	}
	len = ((n == (int)ft_strlen(s)) ? 0 : ft_strlen(s) - len);
	if ((temp = ft_strsub(s, n, len)) == NULL)
		return (NULL);
	return (temp);
}
