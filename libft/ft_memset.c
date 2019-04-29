/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:03:58 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:42:01 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *arr, int c, size_t len)
{
	int i;

	i = 0;
	while (len)
	{
		((unsigned char*)arr)[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (arr);
}
