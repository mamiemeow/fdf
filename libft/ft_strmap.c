/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:24:29 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:48:48 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (s && f)
	{
		i = 0;
		new = (char *)malloc(sizeof(char const) * ft_strlen(s) + 1);
		if (new)
		{
			while (i < (int)ft_strlen(s))
			{
				new[i] = f(s[i]);
				i++;
			}
			new[i] = '\0';
			return (new);
		}
		return (0);
	}
	else
		return (0);
}
