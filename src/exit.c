/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:33:40 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/07 14:33:28 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	ft_exit(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (mlx->fd->tab[i] != NULL)
		free(mlx->fd->tab[i++]);
	free(mlx->fd);
	SDL_DestroyRenderer(mlx->rend);
	SDL_DestroyWindow(mlx->win);
	SDL_Quit();
	free(mlx);
	exit(0);
}
