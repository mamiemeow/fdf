/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 04:22:21 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:51:27 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		while (s1[i] == s2[i])
		{
			if (s2[i + 1] == '\0')
				return ((char *)s1);
			i++;
		}
		i = 0;
		s1++;
	}
	return (0);
}
