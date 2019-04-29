/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:54:41 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:41:15 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;

	if (dst == src)
		return (dst);
	i = 0;
	while (n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
		n--;
	}
	return (dst);
}
