/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:54:40 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/08 15:02:35 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		change_zoom(int av, t_mlx *mlx)
{
	if (mlx->zoom - 1 > 10 || mlx->zoom + 1 < 100)
		mlx->zoom += (av == 0) ? 1 : -1;
	generate_new_image(mlx);
}

int				event_2(t_event touch, t_mlx *mlx)
{
	if (touch.key[45])
		change_zoom(1, mlx);
	else if (touch.key[46])
		change_zoom(0, mlx);
	return (0);
}
