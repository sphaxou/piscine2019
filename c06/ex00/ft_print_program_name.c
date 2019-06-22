/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:19:06 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/09 14:23:15 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int			main(int argc, char **argv)
{
	ft_putstr(argv[argc * 0]);
	ft_putchar('\n');
	return (0);
}
