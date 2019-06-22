/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:35:01 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/22 20:20:08 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	t_dict	*dict;
	char	*s;

	if (ac > 2)
		return (0);
	s = av[1];
	dict = parse("numbers.dict");
	printnumber(s, dict);
	clearmem(dict);
	return (0);
}
