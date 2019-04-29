/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:16:08 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/04/28 15:50:42 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 
# include "mlx.h"
# include <math.h>
# include "libft/includes/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define SIZEX 800
# define SIZEY 800

typedef struct s_map
{
    int height;
    int width;
}t_map;

typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
}t_point;

typedef struct s_win
{
    void *mlx_ptr;
    void *win_ptr;
}t_win;

typedef struct s_global
{
    t_map map;
    t_point *point;
    t_win win;
}t_global;

#endif