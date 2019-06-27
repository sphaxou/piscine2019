/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:55:52 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/20 00:14:22 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_hex(int i, int j, char *b)
{
	if (!j)
		return ;
	print_hex(i / 16, j - 1, b);
	ft_putchar(b[i % 16]);
}

void	print_options(char *s, int i, int j, int size)
{
	ft_putstr("  ");
	j = -1;
	ft_putstr("|");
	while (++j < 16 && i + j < size)
		ft_putchar((s[j] >= 32 && s[j] < 127) ? s[j] : '.');
	ft_putstr("|");
}

void	print_error(char *name, int err)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(err), 2);
	ft_putstr_fd("\n", 2);
}

int		print_line(char *s, int i, int size, int option)
{
	int		j;
	int		k;

	print_hex(i, 7 + option, "0123456789abcdef");
	ft_putchar(' ');
	j = 0;
	while (j < 16 && i + j < size)
	{
		if (option && (!j || j == 8))
			ft_putstr(" ");
		print_hex((unsigned char)s[i + j], 2, "0123456789abcdef");
		if (j != 15 && i + j + 1 < size)
			ft_putchar(' ');
		j++;
	}
	k = j;
	while (k < 16)
		ft_putstr((k++ == 8 && option) ? "    " : "   ");
	if (option)
		print_options(s + i, i, j, size);
	ft_putstr("\n");
	return (j);
}

int		petite_etoile(int star)
{
	if (!star)
		ft_putstr("*\n");
	return (1);
}
