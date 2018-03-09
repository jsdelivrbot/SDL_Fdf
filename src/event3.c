/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:11:55 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/09 11:31:21 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"

static void		move_y(int av, t_mlx *mlx)
{
	mlx->pos.y += ((av == 0) ? 15 : -15);
	generate_new_image(mlx);
}

static void		move_x(int av, t_mlx *mlx)
{
	mlx->pos.x += ((av == 0) ? 15 : -15);
	generate_new_image(mlx);
}

static void		change_alt(int av, t_mlx *mlx)
{
	mlx->alt += (av == 0) ? 1 : -1;
	generate_new_image(mlx);
}

static int 	update_event(t_event *touch, t_mlx *mlx)
{
	SDL_Event		event;
	int					key_code;

	while (SDL_PollEvent(&event))
	{
		key_code = event.key.keysym.scancode;
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			touch->key[key_code] = (event.type == SDL_KEYDOWN) ? 1 : 0;
			break ;
		}
		if (event.type == SDL_QUIT)
		{
			mlx->loop = 0;
			break ;
		}
	}
	return (0);
}

int				event_key(void *init)
{
	t_mlx		*mlx;
	t_event	touch;

	mlx = (t_mlx*)init;
	if (!(touch.key = (char*)ft_memalloc(sizeof(char) * 300)))
		return (-1);
	update_event(&touch, mlx);
	if (touch.key[82])
		move_y(0, mlx);
	else if (touch.key[81])
		move_y(1, mlx);
	else if (touch.key[80])
		move_x(0, mlx);
	else if (touch.key[79])
		move_x(1, mlx);
	else if (touch.key[20])
		change_alt(0, mlx);
	else if (touch.key[26])
		change_alt(1, mlx);
	else if (touch.key[45] || touch.key[46])
		event_2(touch, mlx);
	free(touch.key);
	return (0);
}
