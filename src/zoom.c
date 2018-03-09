/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:07:43 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/28 08:22:49 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			move_re(int av, t_mlx *mlx)
{
	mlx->mv.x += ((av == 0) ? 0.05 : -0.05) / mlx->zoom;
	generate_new_image(mlx);
}

void			zoom(int av, t_mlx *mlx)
{
	if (av == 1 && (mlx->zoom - 0.5) / 2 > 0.2)
		mlx->zoom = (mlx->zoom - 0.5) / 2;
	else if (av == 0)
		mlx->zoom = (mlx->zoom + 0.5) * 2;
	generate_new_image(mlx);
}
