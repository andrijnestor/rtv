/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:44:11 by anestor           #+#    #+#             */
/*   Updated: 2018/01/13 18:55:28 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_spw_cnt(char const *s, char c)
{
	int		count;
	int		n;

	count = 0;
	n = 0;
	while (s[n] != '\0')
	{
		while (s[n] == c && s[n] != '\0')
			n++;
		if (s[n] != '\0')
			count++;
		while (s[n] != c && s[n] != '\0')
			n++;
	}
	return (count);
}

static void	ft_letter_cnt(char const *s, char c, int *n, int *cnt)
{
	*cnt = 0;
	while (s[*n] != c && *n > -1)
	{
		*cnt = *cnt + 1;
		*n = *n - 1;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**temp;
	int		n;
	int		len;
	int		count;

	if (!s)
		return (NULL);
	len = 1 + ft_spw_cnt(s, c);
	if ((temp = (char **)malloc(sizeof(char *) * len)) == NULL)
		return (NULL);
	count = 0;
	n = ft_strlen(s);
	while (--len > -1)
	{
		temp[len] = (count == 0 ? 0 : ft_strsub(s, n + 1, count));
		if (temp[len] == NULL && count != 0)
		{
			free(temp);
			return (NULL);
		}
		while ((s[n] == c || s[n] == '\0') && n > -1)
			n--;
		ft_letter_cnt(s, c, &n, &count);
	}
	return (temp);
}
