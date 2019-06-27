/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:16:03 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/16 16:35:27 by kchhuok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		*init_tab(int *tab, int size)
{
	int i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int*) * size * size)))
		return (NULL);
	while (i < size * size)
		tab[i++] = 0;
	return (tab);
}

int		check(int *tab, int x, int size, int *param)
{
	int i;
	int line;

	i = 0;
	line = x / size * size;
	while (line + i < x)
	{
		if (tab[x] == tab[line + i])
			return (0);
		i++;
	}
	i = 0;
	while ((x % size) + (i * size) < x)
	{
		if (tab[x % size + size * i] == tab[x])
			return (0);
		i++;
	}
	if (!(check_col(tab, x, size, param))
			|| !(check_line(tab, x, size, param)))
		return (0);
	return (1);
}

int		place(int *tab, int i, int size, int *param)
{
	int res;
	int v;

	res = 0;
	if (i >= size * size)
		return (1);
	v = 1;
	while (v <= size && res == 0)
	{
		tab[i] = v;
		if (check(tab, i, size, param) == 1)
			res = place(tab, i + 1, size, param);
		if (!res)
		{
			tab[i] = 0;
		}
		v++;
	}
	return (res);
}

int		solve(char *s, int size)
{
	int	*tab;
	int *param;

	tab = NULL;
	if (size < 3 || size > 9)
		return (0);
	tab = init_tab(tab, size);
	param = ft_parse(s, size);
	if (!(param))
		return (0);
	if (!place(tab, 0, size, param))
		return (0);
	ft_printtab(tab, size);
	free(tab);
	return (1);
}

int		main(int ac, char **av)
{
	int check;

	if (ac == 2)
		check = solve(av[1], 4);
	if (ac == 3)
		check = solve(av[1], ft_atoi(av[2]));
	if ((ac != 2 && ac != 3) || !check)
		ft_putstr("Error\n");
	return (0);
}
