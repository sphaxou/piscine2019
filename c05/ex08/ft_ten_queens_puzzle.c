/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:55:23 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/13 22:15:43 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_pos(int tab[10], int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (tab[i] == tab[x] || tab[i] - tab[x] == x - i
				|| tab[x] - tab[i] == x - i)
			return (0);
		i++;
	}
	return (1);
}

void	print_res(int tab[], int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putchar(tab[i++] + '0');
	ft_putchar('\n');
}

int		solve(int tab[], int x, int size, int *count)
{
	int		i;

	i = 0;
	if (x == size)
	{
		print_res(tab, size);
		*count = *count + 1;
	}
	else
	{
		while (i < size)
		{
			tab[x] = i;
			if (check_pos(tab, x))
			{
				solve(tab, x + 1, size, count);
			}
			i++;
		}
	}
	return (*count);
}

int		ft_ten_queens_puzzle(void)
{
	int		tab[10];
	int		count;

	count = 0;
	solve(tab, 0, 10, &count);
	return (count);
}
