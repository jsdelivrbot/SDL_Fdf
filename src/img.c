/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:04:16 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/09 11:15:21 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	generate_new_image(t_mlx *mlx)
{
	SDL_SetRenderDrawColor(mlx->rend, 0x00, 0x00, 0x00, 1);
	SDL_RenderClear(mlx->rend);
	SDL_SetRenderDrawColor(mlx->rend, 0xFF, 0xA0, 0xA0, 255);
	SDL_GetWindowSize(mlx->win, &mlx->w, &mlx->h);
	//mlx->zoom = start_zoom(mlx);
	put_maps(mlx->fd, mlx);
	SDL_RenderPresent(mlx->rend);
}
