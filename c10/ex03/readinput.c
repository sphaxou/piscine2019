/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:34:26 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 01:47:46 by vgallois         ###   ########.fr       */
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

void	printendinput(char *s, int i, int option)
{
	if (i % 16)
		print_line(s, i - i % 16, i, option);
	if (i)
		print_end(i, option);
}

int		readinput(int option, int star)
{
	char	*s;
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		ret;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char))))
		return (0);
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[BUFF_SIZE] = '\0';
		s = createbigbuff(s, buf);
		i = i + ret;
		if (!(i % 16))
		{
			if (i > 16 && !ft_strncmp(s + i - 16, s + i - 32, 16))
				star = petite_etoile(star);
			else
				star = 0 * print_line(s, i - 16, i, option);
		}
	}
	printendinput(s, i, option);
	return (0);
}
