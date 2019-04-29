/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:33:25 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:52:06 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	if (j < 0)
		return (ft_strdup(""));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (j < i)
		return (ft_strdup(""));
	new = ft_strsub(s, (unsigned int)i, j - i + 1);
	return (new);
}
