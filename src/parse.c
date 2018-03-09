/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:13:22 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/08 12:09:45 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

static int		fd_height(char *file)
{
	char	*line;
	int		fd;
	int		ret;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		height++;
		ft_strdel(&line);
	}
	close(fd);
	if (ret == -1)
		return (-1);
	return (height);
}

static int		check_line(char *line, int *s_len)
{
	t_line	ln;

	ln.i = 0;
	ln.len = 0;
	ln.hexa = 0;
	while (line[ln.i] != '\0')
	{
		if ((ft_isspace(line[ln.i + 1]) == 1 && line[ln.i + 2] != '\0')
				&& ft_isdigit(line[ln.i]) == 1)
			ln.len++;
		if (ft_isdigit(line[ln.i]) == 1 || ft_isspace(line[ln.i]) == 1
				|| line[ln.i] == '\0' || line[ln.i] == '-')
			ln.i++;
		else if (line[ln.i] == ',' && ft_ishexa_color(line + ln.i) == 1)
		{
			ln.hexa++;
			ln.i += 9;
		}
		else
			return (0);
	}
	*s_len = (*s_len == 0) ? ln.len : *s_len;
	if (*s_len != 0 && *s_len != ln.len && ln.hexa == 0)
		return (0);
	return (1);
}

static int		*cpy_split_coord(char **split)
{
	int		len;
	int		i;
	int		*line;

	len = 0;
	i = 0;
	while (split[len])
		len++;
	if (!(line = (int*)malloc(sizeof(int) * (len))))
		return (NULL);
	while (i <= len && split[i] != '\0')
	{
		line[i] = ft_atoi(split[i]);
		ft_strdel(&split[i]);
		i++;
	}
	return (line);
}

static int		**read_fd(char *file, int height, int *len)
{
	int		fd;
	char	**split;
	char	*line;
	int		**coord;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	if (!(coord = (int**)malloc(sizeof(int*) * (height + 1))))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		if (check_line(line, len) == 0)
			return (NULL);
		split = ft_strsplit(line, ' ');
		coord[i] = cpy_split_coord(split);
		i++;
		free(split);
		ft_strdel(&line);
	}
	coord[i] = NULL;
	close(fd);
	return (coord);
}

t_parse			*get_coord(char **av)
{
	t_parse		*coord;
	int			height;
	int			len;
	int			**tab;

	len = 0;
	if (!(coord = (t_parse*)malloc(sizeof(t_parse) * 1)))
		return (NULL);
	if ((height = fd_height(av[1])) == -1
			|| (tab = read_fd(av[1], height, &len)) == NULL)
	{
		free(coord);
		exit(0);
	}
	coord->width = len;
	coord->height = height;
	coord->tab = tab;
	return (coord);
}
