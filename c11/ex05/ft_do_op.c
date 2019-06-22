/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:20:28 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/15 18:12:18 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	do_op(int a, int b, char c)
{
	if (c == '+')
		ft_putnbr(a + b);
	if (c == '-')
		ft_putnbr(a - b);
	if (c == '*')
		ft_putnbr(a * b);
	if (c == '/')
	{
		if (b == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(a / b);
	}
	if (c == '%')
	{
		if (b == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(a % b);
	}
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	char op;

	if (ac != 4)
		return (0);
	op = av[2][0];
	if (!av[2][1]
		&& (op == '+' || op == '-' || op == '*' || op == '/' || op == '%'))
		do_op(ft_atoi(av[1]), ft_atoi(av[3]), op);
	else
		ft_putstr("0\n");
	return (0);
}
