/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:49:27 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/05 14:09:57 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putpositivenb(int n, int count)
{
	if (n == 0)
	{
		if (count == 0)
			return ;
	}
	ft_putpositivenb(n / 10, count - 1);
	ft_putchar('0' + n % 10);
}

int			ft_exp(int a, int b)
{
	int res;

	res = 1;
	if (b == 0)
		return (res);
	if (b > 0)
	{
		while (b > 0)
		{
			res = res * a;
			b--;
		}
	}
	return (res);
}

void		ft_print_combn(int n)
{
	int	a;
	int	max;

	if (n < 1 || n > 9)
		return ;
	max = ft_exp(10, n);
	a = n;
	while (a)
	{
		write(1, "0", 1);
		a--;
	}
	write(1, ", ", 2);
	a = 1;
	while (a < max)
	{
		ft_putpositivenb(a, n);
		(a == max - 1) ? write(1, "\n", 1) : write(1, ", ", 2);
		a++;
	}
}
