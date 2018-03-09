/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:29:27 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/28 08:32:13 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static void		move_im(int av, t_mlx *mlx)
{
	mlx->mv.y += ((av == 0) ? 0.05 : -0.05) / mlx->zoom;
	generate_new_image(mlx);
}

static void		select_index(void (*f[5][3])(int, t_mlx*), int *neg, int key)
{
	if (key == LEFT || key == DOWN || key == ZOOM_DOWN || key == ZOOM_DOWN2)
		*neg = 1;
	f[0][0] = (void*)ft_itoa(LEFT);
	f[0][1] = (void*)ft_itoa(RIGHT);
	f[0][2] = move_re;
	f[1][0] = (void*)ft_itoa(UP);
	f[1][1] = (void*)ft_itoa(DOWN);
	f[1][2] = move_im;
	f[2][0] = (void*)ft_itoa(ZOOM_UP);
	f[2][1] = (void*)ft_itoa(ZOOM_DOWN);
	f[2][2] = zoom;
	f[3][0] = (void*)ft_itoa(ZOOM_UP2);
	f[3][1] = (void*)ft_itoa(ZOOM_DOWN2);
	f[3][2] = zoom;
	f[4][0] = (void*)ft_itoa(0);
	f[4][1] = (void*)ft_itoa(0);
	f[4][2] = NULL;
}

static int		change_fractal(int key, t_mlx *mlx)
{
	if (key == 18)
		mlx->fractal = 0;
	else if (key == 19)
		mlx->fractal = 1;
	else if (key == 20)
		mlx->fractal = 2;
	else if (key == 21)
		mlx->fractal = 3;
	else if (key == 23)
		mlx->fractal = 4;
	else if (key == 22)
		mlx->fractal = 5;
	else if (key == 26)
		mlx->fractal = 6;
	reset(mlx);
	return (0);
}

static int		event(int key, t_mlx *mlx)
{
	if (key == EXIT)
		ft_exit(mlx);
	else if (key == RESET)
		reset(mlx);
	else if (key == SPACE)
		mlx->mv_julia = (mlx->mv_julia == 0) ? 1 : 0;
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23
			|| key == 22 || key == 26)
		change_fractal(key, mlx);
	else if (key == 17 || key == 11 || key == 5
			|| key == 13 || key == 12 || key == 0)
		event_color(key, mlx);
	return (0);
}

int				key_event(int key, void *init)
{
	t_mlx	*mlx;
	int		i;
	int		neg;
	void	(*f[5][3])(int, t_mlx *);

	mlx = (t_mlx*)init;
	i = 0;
	neg = 0;
	select_index(f, &neg, key);
	while (key != ft_atoi((char*)f[i][0]) && key != ft_atoi((char*)f[i][1]))
	{
		if (i > 3)
			break ;
		i++;
	}
	if (i < 4)
		(*f[i][2])(neg, mlx);
	ft_free_f(f);
	event(key, mlx);
	return (0);
}
