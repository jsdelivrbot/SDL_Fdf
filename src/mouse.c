/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 07:35:34 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/27 12:50:01 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

int				tracer(int x, int y, void *init)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)init;
	if (mlx->mv_julia == 0)
	{
		mlx->julia.y = (y - W_HEIGHT / 2) / (W_WIDTH - mlx->zoom * 2);
		mlx->julia.x = (x - W_WIDTH / 2) / (W_WIDTH - mlx->zoom * 2);
		generate_new_image(mlx);
	}
	return (0);
}

int				mouse_event(int button, int x, int y, void *init)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)init;
	if (button == 5)
	{
		mlx->zoom = (mlx->zoom + 0.5) * 2;
		mlx->mv.x += (((x - (W_WIDTH / 2)) / 100) / mlx->zoom);
		mlx->mv.y += (((y - (W_HEIGHT / 2)) / 100) / mlx->zoom);
		generate_new_image(mlx);
	}
	else if (button == 4)
		zoom(1, mlx);
	else if (button == 1)
		mlx->mv_julia = (mlx->mv_julia == 0) ? 1 : 0;
	else if (button == 6)
		move_re(0, mlx);
	else if (button == 7)
		move_re(1, mlx);
	return (0);
}
