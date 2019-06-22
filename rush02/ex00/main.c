/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:35:01 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 00:05:12 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_dict	*dict;
	char	*s;

	if (ac > 2)
		return (0);
	s = av[1];
	dict = parse("numbers.dict");
//	int i = 0;
//	while (dict[i].len != 0)
//	{
//		printf("dict[%d]:\n%s\n%s\n", i, dict[i].number, dict[i].str);
//		i++;
//	}
	printf("parse ok\n");
	//sortdict(&dict);
	//printf("sort ok\n");
	printnumber(s, ft_strlen(s), dict);
	//cleanmem(dict);
	return (0);
}