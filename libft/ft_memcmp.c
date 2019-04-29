/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:20:58 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:31:49 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *r1;
	unsigned char *r2;

	if (n == 0)
		return (0);
	r1 = (unsigned char*)s1;
	r2 = (unsigned char*)s2;
	while (n - 1 && *r1 == *r2)
	{
		r1++;
		r2++;
		n--;
	}
	return (*r1 - *r2);
}
