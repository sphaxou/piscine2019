/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:23:29 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/19 21:47:47 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *s)
{
	int		i;
	char	*b;

	i = 0;
	b = "0123456789abcdef";
	while (s[i])
	{
		if (s[i] >= 32 && s[i] < 127)
			ft_putchar(s[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(b[(unsigned char)s[i] / 16]);
			ft_putchar(b[(unsigned char)s[i] % 16]);
		}
		i++;
	}
}
