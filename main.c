/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:07:02 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/04/29 17:28:31 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void iso(t_global *global)
{
	int i;
	
	i = 0;
	while (i < global->map.width * global->map.height)
	{
		global->point[i].x = (global->point[i].x - global->point[i].y) * cos(0.523599) + SIZEX/2;
		global->point[i].y = -global->point[i].z + (global->point[i].x + global->point[i].y) * sin(0.523599);
		i++;
	}
}

void	bresenham(t_point dot1, t_point dot2, t_global *global)
{
	const int deltaX = abs(dot2.x - dot1.x);
	const int deltaY = abs(dot2.y - dot1.y);
	const int signX = dot1.x < dot2.x ? 1 : -1;
	const int signY = dot1.y < dot2.y ? 1 : -1;
	int error = deltaX - deltaY;

	while (dot1.x != dot2.x || dot1.y != dot2.y)
	{
    	mlx_pixel_put(global->win.mlx_ptr, global->win.win_ptr, dot1.x, dot1.y, 0xD8BFD8);
      	int error2 = error * 2;
		  
       	if (error2 > -deltaY)
       	{
        	error -= deltaY;
           	dot1.x += signX;
    	}
    	if (error2 < deltaX)
    	{
        	error += deltaX;
        	dot1.y += signY;
    	}
	}
}

void	draw(t_global *global)
{
	int x;
	int y;

	y = 0;
	while(y < global->map.height)
	{
		x = 0;
		while (x < global->map.width)
		{
			if (x + 1 < global->map.width)
				bresenham(global->point[y * global->map.width + x], global->point[y * global->map.width + x + 1], global);
			 if (y + 1 < global->map.height)
			 	bresenham(global->point[y * global->map.width + x], global->point[(y + 1) * global->map.width + x], global);
			x++;
		}
		y++;
	}
}

void	deal_key(int key, void *pen)
{
	int i;
	t_global *global;

	global = pen;
	i = 0;

	if (key == 53)
		exit(0);
	if (key == 124)
	{
		while (i < global->map.width * global->map.height)
		{
			mlx_clear_window(global->win.mlx_ptr, global->win.win_ptr);
			global->point[i].y = global->point[i].y * cos(0.349066) + global->point[i].z * sin(0.349066);
			global->point[i].z = -global->point[i].y * sin(0.349066) + global->point[i].z * cos(0.349066);
			global->point[i].y += SIZEX / 2 - global->map.height * SIZEX/60;
			i++;
		}
		draw(global);
	}
	if (key == 19)
	{
		mlx_clear_window(global->win.mlx_ptr, global->win.win_ptr);
		iso(global);
		draw(global);
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			width;
	int			height;
	char		**string;
	t_global	*global;
	int			i;
	int			j;
	
	if (argc == 5)
		exit(0);
	i = 0;
	global = NULL;
	width = 0;
	height = 0;
	fd = open(argv[1], O_RDONLY);
	global = (t_global *)malloc(sizeof(t_global));
	while (get_next_line(fd, &line) > 0)
	{
		string = ft_strsplit(line, ' ');
		while (string[width])
			width++;
		height++;
	}
	global->map.height = height;
	global->map.width = width;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	j = 0;
	i = 0;
	global->point = (t_point *)malloc((global->map.width * global->map.height) * sizeof(t_point));
	while (get_next_line(fd, &line) > 0)
	{
		string = ft_strsplit(line, ' ');
		j = 0;
		while (string[j])
		{
			global->point[i].x = (j % global->map.width * SIZEX / 30) + SIZEX / 2 - global->map.width * SIZEX/60;
			global->point[i].y = (i / global->map.width * SIZEY/30) + SIZEY/2 - global->map.height * SIZEY/60;
			global->point[i].z = ft_atoi(string[j]) * SIZEX/(SIZEX/3);
			j++;
			i++;
		}
	}
	i = 0;
	global->win.mlx_ptr = mlx_init();
	global->win.win_ptr = mlx_new_window(global->win.mlx_ptr, SIZEX, SIZEY, "meow");
	draw(global);
	mlx_key_hook(global->win.win_ptr, (void *)deal_key, (void *)global);
	mlx_loop(global->win.mlx_ptr);
}
