/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:29:28 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/27 11:51:48 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUFF_SIZE 500000
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int		file_size(char *s)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		size;

	size = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (0);
		size = size + ret;
	}
	close(fd);
	return (size);
}

char	*read_file(char *s, int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (file_size(s) + 1))))
		return (NULL);
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Open error\n", 2);
		return (NULL);
	}
	res[0] = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			ft_putstr_fd("Read error\n", 2);
			return (NULL);
		}
		buff[ret] = '\0';
		res = ft_strcat(res, buff);
	}
	close(fd);
	return (res);
}

int		assign_car(char *s, t_car *car)
{
	int		link;

	car->h = 0;
	while (s[car->h] && s[car->h] != '\n')
		car->h++;
	if (car->h < 4)
		return (0);
	car->vide = s[car->h - 3];
	car->obs = s[car->h - 2];
	car->plein = s[car->h - 1];
	link = car->h;
	car->h = ft_atoi_len(s, car->h - 3);
	return (link);
}

/*
** link se deplace sur la map, mais si la map n'est pas valide
** car zelda n'est pas la, il est bien triste
*/

int		zelda(char *s, t_car *car, int l, int link)
{
	int		l1;
	int		h;

	link = assign_car(s, car);
	h = -1;
	l1 = 0;
	while (s[link])
	{
		if (s[link] == '\n')
		{
			if (l1 && l1 != l)
				return (0);
			l1 = l;
			l = 0;
			h++;
		}
		if (!(s[link] == car->vide || s[link] == car->obs || s[link] == '\n'))
			return (3);
		l++;
		link++;
	}
	if (h != car->h)
		return (2);
	return (1);
}

int		**parse(char *file, t_car *car, int *h, int *l)
{
	int		**map;
	char	*s;
	int		link;
	int		navi;

	link = 0;
	s = read_file(file, 0);
	if (!s || zelda(s, car, 0, 0) != 1 || !(car->h))
	{
		if (s)
			ft_putstr_fd("map error\n", 2);
		return (NULL);
	}
	*h = car->h;
	while (s[link] && s[link] != '\n')
		link++;
	link = link + 1;
	navi = link;
	while (s[link++] != '\n')
		*l += 1;
	map = splitint(s + navi, *car, *h, *l);
	return (map);
}
