/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:53:37 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/09 12:31:11 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL.h>
#include "fdf.h"

int				start_zoom(t_mlx *init)
{
	int		x_max;
	int		y_max;
	int		i;
	int		j;

	i = 2;
	j = 2;
	x_max = (init->fd->width - init->fd->height);
	y_max = (init->fd->width + init->fd->height / 2);
	init->iso.x = x_max;
	init->iso.y = y_max;
	while (i * x_max < init->w && j * y_max < init->h)
	{
		++i;
		++j;
	}
	--i;
	--j;
	if (i == j)
		return (i);
	return (j);
}

static t_mlx	*init_win(t_mlx *init)
{
	SDL_Init(SDL_INIT_VIDEO);
	init->win = SDL_CreateWindow("Fdf", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_SetWindowMinimumSize(init->win, W_WIDTH, W_HEIGHT);
	SDL_GetWindowSize(init->win, &init->w, &init->h);
	init->rend = SDL_CreateRenderer(init->win, -1, SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);
	init->alt = 1;
	init->loop = 1;
	init->zoom = start_zoom(init);
	init->pos.x = 0;
	init->pos.y = 0;
	init->color = 0xFF00FF;
	return (init);
}

int				main(int ac, char **av)
{
	t_mlx				*init;

	if (ac != 2)
	{
		ft_putendl("usage : ./fdf source_file.fdf");
		return (0);
	}
	if (!(init = (t_mlx*)malloc(sizeof(t_mlx))))
		return (-1);
	init->fd = get_coord(av);
	init = init_win(init);
	while (init->loop)
	{
		generate_new_image(init);
		event_key(init);
	}
	ft_exit(init);
	return (0);
}
