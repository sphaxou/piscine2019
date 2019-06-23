/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:23:30 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 03:10:10 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	bsq(char *s)
{
	int		h;
	int		l;
	char	**tab;
	t_car	car;

	tab = parse(s, &car, &h, &l);
	if (!tab)
		return (0);
	return (1);
}
