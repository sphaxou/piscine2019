/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:21:46 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 06:26:34 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
 #include <time.h>

int main(int ac, char **av)
{
	int i;
	 clock_t start, end;
	      double cpu_time_used;
		       
		       start = clock();

	if (ac == 1)
	{
		ft_putstr_fd("No argument\n", 2);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		bsq(av[i++]);
		if (i != ac)
			ft_putstr("\n");
	}
	end = clock();
	     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	return (0);
}
