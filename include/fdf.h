/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:09:51 by cpieri            #+#    #+#             */
/*   Updated: 2018/03/09 11:12:17 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <SDL.h>
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"

# define W_WIDTH	1227
# define W_HEIGHT	912

typedef struct		s_img
{
	void			*img_s;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_parse
{
	int				width;
	int				height;
	int				**tab;
}					t_parse;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_mlx
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	int				w;
	int				h;
	int				loop;
	t_img			img;
	t_point			pos;
	t_point			iso;
	t_parse			*fd;
	int				alt;
	int				zoom;
	int				color;
}					t_mlx;

typedef struct		s_event
{
	char						*key;
}									t_event;

typedef struct		s_coord
{
	t_point			p1;
	t_point			p2;
	t_point			i;
}					t_coord;

typedef struct		s_draw
{
	int				x;
	int				y;
	int				x_1;
	int				y_1;
}					t_draw;

typedef struct		s_line
{
	int				i;
	int				len;
	int				hexa;
}					t_line;

typedef struct		s_bres
{
	int				ex;
	int				ey;
	int				err;
	int				e;
}					t_bres;

int					main(int ac, char **av);
int					start_zoom(t_mlx *init);
int					event_key(void *init);
int				event_2(t_event touch, t_mlx *mlx);
int					event_color(int key, t_mlx *mlx);
t_parse				*get_coord(char **av);
void				put_maps(t_parse *fd, t_mlx *init);
void				bresenham(t_point *p1, t_point *p2, t_mlx *mlx);
void				ft_exit(t_mlx *mlx);
void				generate_new_image(t_mlx *mlx);

#endif
