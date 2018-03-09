/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:49:41 by anestor           #+#    #+#             */
/*   Updated: 2017/11/08 16:25:45 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*tmp_lst;

	if (new && alst)
	{
		tmp_lst = *alst;
		if (*alst)
		{
			while (tmp_lst->next)
				tmp_lst = tmp_lst->next;
			tmp_lst->next = new;
		}
		else
			*alst = new;
	}
}
