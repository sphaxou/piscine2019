/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:34:26 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 02:03:40 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUFF_SIZE 1
#include <stdlib.h>

char	*createbigbuff(char *s, char *buff)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(s)
				+ ft_strlen(buff) + 1))))
		return (NULL);
	res = ft_strcpy(res, s);
	free(s);
	res = ft_strcat(res, buff);
	return (res);
}

void	displayinput(char *s, int size, int offset)
{
	int		i;

	i = 0;
	while (i < size - offset)
		i++;
	while (i < size)
		write(1, s + i++, 1);
}

int		readinput(int offset)
{
	char	*s;
	char	buf[BUFF_SIZE + 1];

	if (!(s = (char*)malloc(sizeof(char))))
		return (0);
	while (read(0, buf, BUFF_SIZE))
	{
		buf[BUFF_SIZE] = '\0';
		s = createbigbuff(s, buf);
	}
	displayinput(s, ft_strlen(s), offset);
	free(s);
	return (0);
}
