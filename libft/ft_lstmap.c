/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:39:29 by anestor           #+#    #+#             */
/*   Updated: 2017/11/01 19:49:33 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;

	if (lst && f)
	{
		if (lst->next)
		{
			temp = ft_lstmap(lst->next, f);
			ft_lstadd(&temp, f(lst));
		}
		else
			temp = f(lst);
		return (temp);
	}
	return (NULL);
}
