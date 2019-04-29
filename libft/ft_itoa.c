/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:37:01 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:26:39 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int			ft_len(int n)
{
	int				i;
	unsigned int	c;

	c = n;
	i = n ? 0 : 1;
	if (n < 0)
	{
		c = -n;
		i++;
	}
	while (c)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char			*new;
	int				i;
	unsigned int	c;

	i = ft_len(n);
	if (!(new = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	new[0] = '0';
	new[i] = '\0';
	if (n < 0)
		new[0] = '-';
	c = n < 0 ? -n : n;
	i--;
	while (c)
	{
		new[i] = (c % 10) + 48;
		c = c / 10;
		i--;
	}
	return (new);
}
