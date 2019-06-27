/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 01:47:01 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 00:15:42 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUFF_SIZE 1

void	display_name(char *s)
{
	ft_putstr("==> ");
	ft_putstr(s);
	ft_putstr(" <==\n");
}

int		size_file(char *s)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		size;

	size = 0;
	errno = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (-1);
	}
	while ((ret = read(fd, buf, 1)))
		size++;
	close(fd);
	return (size);
}

void	display_content(int fd, int size, int offset)
{
	int		i;
	int		ret;
	char	buff[2];

	i = 0;
	while (i < size - offset && (ret = read(fd, buff, 1)))
		i++;
	while ((ret = read(fd, buff, 1)))
	{
		buff[1] = '\0';
		ft_putstr(buff);
	}
}

void	display_files_offset(int ac, char **av, int offset)
{
	int		i;
	int		fd;
	int		size;

	i = 3;
	while (i < ac)
	{
		errno = 0;
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			display_error_tail(av, errno, i);
		else
		{
			if (i > 3)
				ft_putstr("\n");
			if (ac >= 5)
				display_name(av[i]);
			size = size_file(av[i]);
			display_content(fd, size, offset);
		}
		close(fd);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		offset;

	if (ac == 1)
		return (readinput(0));
	if (ac == 2)
		display_usage_tail(av);
	if (ac >= 3)
	{
		offset = ft_atoi(av[2]);
		if (ac == 3 && (ft_str_is_num(av[2])))
			return (readinput(offset));
		if (!ft_str_is_num(av[2]))
		{
			if (!ft_str_is_num(av[2]) && av[2][0] != '+' && av[2][0] != '-')
				offset_error(av);
			else
				return (0);
		}
		display_files_offset(ac, av, offset);
	}
	return (0);
}
