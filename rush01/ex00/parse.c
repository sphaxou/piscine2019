/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:51:35 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/16 07:19:28 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		*ft_parse(char *s, int size)
{
	int		i;
	int		j;
	int		*param;

	if (!(param = (int *)malloc(sizeof(int) * size * size)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (ft_is_whitespace(s[i]))
			i++;
		if (s[i])
			param[j++] = ft_atoi(s + i);
		while (s[i] && !ft_is_whitespace(s[i]))
			i++;
	}
	if (j < 4 * size)
	{
		free(param);
		return (NULL);
	}
	return (param);
}
