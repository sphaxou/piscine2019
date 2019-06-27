/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 01:47:01 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 01:37:52 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUFF_SIZE 1

int		main(int ac, char **av)
{
	int		option;

	option = 0;
	if (ac == 1)
		return (readinput(0, 0));
	if (ac == 2 && !ft_strcmp(av[1], "-C"))
		return (readinput(1, 0));
	if (!ft_strcmp(av[1], "-C"))
		option = 1;
	ft_hexdump(av, option, 0, 0);
	return (0);
}
