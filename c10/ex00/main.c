/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 01:08:02 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/22 20:16:23 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUF_SIZE 4096

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (ac == 1 || ac > 2)
	{
		if (ac == 1)
			ft_putstr_fd("File name missing.\n", 2);
		if (ac > 2)
			ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
		write(1, buf, ret);
	close(fd);
	return (0);
}
