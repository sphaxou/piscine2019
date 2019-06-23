/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:35:01 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 02:11:58 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_dict	*dict;
	char	*s;

	if (ac == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (ac > 2)
		return (0);
	s = av[1];
	dict = parse("numbers.dict");
	int i = 0;
	while (dict[i].len != 0)
	{
		printf("%s %s\n", dict[i].number, dict[i].str);
		i++;
	}
	printf("parse ok\n");
	sortdict(dict);
	i = 0;
	while (dict[i].len != 0)
	{
		printf("%s %s\n", dict[i].number, dict[i].str);
		i++;
	}
	printf("sort ok\n");
	printnumber(s, ft_strlen(s), dict);
	ft_putstr("\n");
	//cleanmem(dict);
	return (0);
}
