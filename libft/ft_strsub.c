/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 03:17:05 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:51:44 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (!(s))
		return (0);
	new = (char *)malloc(sizeof(char) * n + 1);
	if (new)
	{
		while (i < n)
		{
			new[i] = s[start];
			i++;
			start++;
		}
		new[i] = '\0';
	}
	return (new);
}
