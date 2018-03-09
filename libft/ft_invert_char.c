/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:17:04 by anestor           #+#    #+#             */
/*   Updated: 2017/11/06 17:01:39 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_invert_char(char *string, char c1, char c2)
{
	char	*inverted;

	if (!string)
		return (NULL);
	inverted = ft_strsub(string, 0, ft_strlen(string));
	while (*inverted != '\0')
	{
		if (*inverted == c1)
			*inverted = c2;
		else if (*inverted == c2)
			*inverted = c1;
		inverted++;
	}
	return (inverted - ft_strlen(string));
}
