/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:56:05 by anestor           #+#    #+#             */
/*   Updated: 2018/01/13 19:22:59 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
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
