/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:04:42 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/09 12:35:48 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		blue_col(t_mlx *mlx)
{
	mlx->color = 0x0000FF;
	generate_new_image(mlx);
}

static void		green_col(t_mlx *mlx)
{
	mlx->color = 0x00FF00;
	generate_new_image(mlx);
}

static void		red_col(t_mlx *mlx)
{
	mlx->color = 0xFF0000;
	generate_new_image(mlx);
}

static void		color(t_mlx *mlx)
{
	mlx->color += 10;
	generate_new_image(mlx);
}

int				event_color(int key, t_mlx *mlx)
{
	if (key == 45)
		color(mlx);
	else if (key == 15)
		red_col(mlx);
	else if (key == 5)
		green_col(mlx);
	else if (key == 11)
		blue_col(mlx);
	return (0);
}
