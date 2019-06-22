/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 00:18:40 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/05 00:18:46 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_nominzero(int nb)
{
	if (nb > 0)
	{
		ft_putnbr_nominzero(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			if (nb < 0)
			{
				write(1, "-", 1);
				ft_putnbr_nominzero(-nb);
			}
			else
				ft_putnbr_nominzero(nb);
		}
	}
}
