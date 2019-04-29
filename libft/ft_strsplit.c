/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:24:53 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/01/29 20:51:14 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_countword(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static size_t	ft_lenword(char *s, char c)
{
	int			i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void		ft_free(char **new, int i)
{
	while (--i >= 0)
	{
		free(new[i]);
		new[i] = NULL;
	}
	free(new);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**new;
	int			word;
	int			i;

	i = 0;
	if (!s || !c)
		return (0);
	word = ft_countword(s, c);
	if (!(new = (char**)malloc(sizeof(char *) * (word + 1))))
		return (0);
	new[word] = 0;
	while (s && i < word)
	{
		while (*s == c)
			s++;
		if (!(new[i] = ft_strsub(s, 0, ft_lenword((char *)s, c))))
			ft_free(new, i);
		i++;
		s += (int)ft_lenword((char *)s, c);
	}
	return (new);
}
