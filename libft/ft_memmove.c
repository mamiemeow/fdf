/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:35:06 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:41:46 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ddst;
	unsigned char	*ssrc;

	if (dst == src)
		return (dst);
	ddst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	i = 0;
	if (ddst < ssrc)
	{
		while (i < n)
		{
			ddst[i] = ssrc[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (n--)
			ddst[n] = ssrc[n];
	}
	return (dst);
}
