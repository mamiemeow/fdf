/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:13:50 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:28:28 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;

	if (!lst || !f || !(new = f(lst)))
		return (NULL);
	begin = new;
	while (lst->next)
	{
		if (!(new->next = f(lst->next)))
		{
			while (begin)
			{
				new = begin->next;
				free(begin);
				begin = new;
			}
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (begin);
}
