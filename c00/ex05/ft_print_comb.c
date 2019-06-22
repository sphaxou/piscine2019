/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 22:48:16 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/07 12:35:37 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int b;
	int c;

	a = 0;
	while (a <= 9)
	{
		b = a + 1;
		while (b < 10)
		{
			c = b + 1;
			while (c < 10)
			{
				ft_putchar(a + '0');
				ft_putchar(b + '0');
				ft_putchar(c + '0');
				if (a * 100 + b * 10 + c != 789)
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
