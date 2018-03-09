/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:53:17 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/07 14:14:06 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	bresenham(t_point *p1, t_point *p2, t_mlx *mlx)
{
	t_bres		e;

	e.ex = labs(p2->x - p1->x);
	e.ey = labs(p2->y - p1->y);
	e.err = (e.ex > e.ey ? e.ex : -e.ey) / 2;
	while (p1->x != p2->x || p1->y != p2->y)
	{
		if (p1->y > 0 && p1->y < W_HEIGHT && p1->x > 0 && p1->x < W_WIDTH)
		{
			SDL_RenderDrawPoint(mlx->rend, p1->x, p1->y);
			//mlx->img.data[(p1->y * mlx->img.size_l / 4) + (p1->x)] = mlx->color;
			e.e = e.err;
			if (e.e > -e.ex)
			{
				(p1->x > p2->x) ? (p1->x--) : (p1->x++);
				e.err -= e.ey;
			}
			if (e.e < e.ey)
			{
				(p1->y > p2->y) ? (p1->y--) : (p1->y++);
				e.err += e.ex;
			}
		}
		else
			break ;
	}
}
