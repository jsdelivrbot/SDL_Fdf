/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:51:39 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/07 11:32:44 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL.h>

int		main(int ac, char **av)
{
	int				loop;
	int				w;
	int				h;
	SDL_Surface		*screen;
	SDL_Window		*win;
	SDL_Renderer	*renderer;

	win = 0;
	loop = 1;
	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("RT_v1", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	while (loop)
	{
		SDL_Event(event);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xA0, 0xA0, 1);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 1);
		SDL_RenderDrawLine(renderer, 0, 0, w, h);
		SDL_RenderPresent(renderer);
		SDL_GetWindowSize(win, &w, &h);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				loop = 0;
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
