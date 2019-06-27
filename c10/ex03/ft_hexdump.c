/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:20:14 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/20 01:04:17 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <libgen.h>

int		file_size(char *file)
{
	int		fd;
	char	buf[2];
	int		ret;
	int		size;

	size = 0;
	errno = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, 1)))
		size++;
	close(fd);
	return (size);
}

char	*create_big_buf(char **av, int i, int *size, int option)
{
	char	buff[2];
	int		fd;
	char	*res;
	int		ret;

	while (av[i])
		*size = *size + file_size(av[i++]);
	if (*size == -1 || !(res = (char *)malloc(sizeof(char) * (*size + 1))))
		return (NULL);
	res[0] = '\0';
	i = option;
	while (av[++i])
	{
		errno = 0;
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			print_error(basename(av[0]), errno);
		else
			while ((ret = read(fd, buff, 1)))
			{
				buff[1] = '\0';
				res = ft_strcat(res, buff);
			}
	}
	return (res);
}

void	print_end(int i, int option)
{
	print_hex(i, 7 + option, "0123456789abcdef");
	ft_putstr("\n");
}

void	ft_hexdump(char **av, int option, int printed, int star)
{
	int		i;
	char	*s;
	int		j;
	int		size;

	size = 0;
	s = create_big_buf(av, 1 + option, &size, option);
	i = 0;
	while (s[i])
	{
		printed = 1;
		if (i >= 16 && !(ft_strncmp(s + i, s + i - 16, 16)))
			star = petite_etoile(star);
		else
		{
			j = print_line(s, i, size, option);
			star = 0;
		}
		i += j;
	}
	if (printed)
		print_end(i, option);
	free(s);
}
