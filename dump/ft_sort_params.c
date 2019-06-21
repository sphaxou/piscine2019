/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:52:24 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/09 18:01:04 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned int)(s1[i]) - (unsigned int)(s2[i]));
}

void	ft_print_sort_strings(char **av, int size)
{
	int 	i;
	int		imin;

	if (size < 1)
		return ;
	i = 0;
	imin = 0;
	while (av[i] && i < size)
	{
		if (ft_strcmp(av[i], av[imin]) < 0)
			imin = i;
		i++;
	}
	ft_putstr(av[imin]);
	ft_putchar('\n');
	av[imin] = av[0];
	ft_print_sort_strings(av + 1, size - 1);
}

int		main(int ac, char **av)
{
	ft_print_sort_strings(av + 1, ac - 1);
	return (0);
}	
