/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 01:57:46 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/02/07 23:00:51 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*new;

	new = (char *)s;
	i = 0;
	while (new[i])
	{
		if (new[i] == (char)c)
			return (new + i);
		i++;
	}
	if (c == '\0')
		return (new + i);
	return (0);
}
