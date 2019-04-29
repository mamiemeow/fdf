/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:01:22 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:49:31 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	k;

	k = (int)n;
	if (n == 0)
		return (0);
	i = 0;
	while (n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
		n--;
	}
	if (i == (int)k)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
