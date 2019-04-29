/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:46:54 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/04/19 14:39:48 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

static int		ft_check(char **stack, char **line)
{
	char	*new;
	char	*tmp;
	char	*arr;
	char	*keep;
	int		i;

	i = 0;
	new = *stack;
	while (new[i] != '\n')
		if (!new[i++])
			return (0);
	keep = &new[i];
	*keep = '\0';
	arr = ft_strdup(*stack);
	free(*line);
	*line = arr;
	tmp = ft_strdup(keep + 1);
	free(*stack);
	*stack = tmp;
	return (1);
}

static int		ft_helpme(int fd, char **stack, char **line)
{
	int			ret;
	char		*tmp;
	char		kycha[BUFF_SIZE + 1];

	while ((ret = read(fd, kycha, BUFF_SIZE)) > 0)
	{
		kycha[ret] = '\0';
		if (*stack)
		{
			tmp = *stack;
			*stack = ft_strjoin(tmp, kycha);
			free(tmp);
			if (ft_check(stack, line))
				return (1);
		}
		else
			*stack = ft_strdup(kycha);
		if (ft_check(stack, line))
			return (1);
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stack[FD];
	int			ret;

	if (fd < 0 || line == NULL || fd >= FD)
		return (-1);
	*line = ft_strnew(1);
	if (stack[fd])
		if (ft_check(&stack[fd], line))
			return (1);
	if ((ret = ft_helpme(fd, &stack[fd], line)) == 1)
		return (1);
	if (ret == -1)
		return (-1);
	if ((ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0'))
		return (ret);
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
