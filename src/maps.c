/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:14:23 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/07 14:17:53 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void		change_to_iso(t_point *p, int z, int h)
{
	int		iso_x;
	int		iso_y;

	iso_x = (p->x - p->y);
	iso_y = (p->x + p->y / 2) - (z * h);
	p->x = iso_x;
	p->y = iso_y;
}

static void		init_draw_point(int arg, t_draw *d)
{
	d->x = 0;
	d->y = 0;
	d->y_1 = 0;
	d->x_1 = 0;
	if (arg == 0)
		d->x = 1;
	if (arg == 1)
		d->y = 1;
	if (arg == 2 || arg == 3)
	{
		d->x = 1;
		d->y = 1;
		if (arg == 2)
			d->x_1 = 1;
		if (arg == 3)
			d->y_1 = 1;
	}
}

static void		coord_to_print(int arg, t_coord *p, t_parse *fd, t_mlx *init)
{
	t_draw		d;

	if ((p->i.x <= fd->width && p->i.x + 1 > fd->width)
			|| fd->tab[p->i.y + 1] == NULL)
		return ;
	init_draw_point(arg, &d);
	p->p1.x = (p->i.x + d.x_1) * init->zoom;
	p->p1.y = (p->i.y + d.y_1) * init->zoom;
	p->p2.x = (p->i.x + d.x) * init->zoom;
	p->p2.y = (p->i.y + d.y) * init->zoom;
	change_to_iso(&(p->p1), fd->tab[p->i.y + d.y_1][p->i.x + d.x_1], init->alt);
	if (!(fd->tab[p->i.y + d.y] == NULL) || !(p->i.x + d.x > fd->width))
		change_to_iso(&(p->p2), fd->tab[p->i.y + d.y][p->i.x + d.x], init->alt);
	p->p1.x += (init->w - ((init->iso.x * init->zoom) - init->pos.x)) / 2;
	p->p1.y += (init->h - ((init->iso.y * init->zoom) - init->pos.y)) / 2;
	p->p2.x += (init->w - ((init->iso.x * init->zoom) - init->pos.x)) / 2;
	p->p2.y += (init->h - ((init->iso.y * init->zoom) - init->pos.y)) / 2;
	SDL_RenderDrawLine(init->rend, p->p1.x, p->p1.y, p->p2.x, p->p2.y);
}

void			put_maps(t_parse *fd, t_mlx *init)
{
	t_coord		p;

	p.i.y = 0;
	while (fd->tab[p.i.y] != NULL)
	{
		p.i.x = 0;
		while (p.i.x <= fd->width)
		{
			coord_to_print(0, &p, fd, init);
			coord_to_print(1, &p, fd, init);
			coord_to_print(2, &p, fd, init);
			coord_to_print(3, &p, fd, init);
			p.i.x++;
		}
		p.i.y++;
	}
}
