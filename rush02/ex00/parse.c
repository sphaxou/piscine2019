/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02-v0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:25:09 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/22 21:57:22 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

#define BUF_SIZE 10000

char	*ft_read(char *s)
{
	char buff[BUF_SIZE + 1];
	int		ret;
	char	*str;
	int		len;
	int		fd;

	len = 0;
	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buff, BUF_SIZE)))
		len = len + ret;
	close(fd);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[0] = '\0';
	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buff, BUF_SIZE)))
	{
		buff[ret] = '\0';
		str = ft_strcat(str, buff);
	}
	close(fd);
	return (str);
}

int		count_line(char *s)
{
	int		fd;
	char	buf[1];
	int		ret;
	int		count;

	count = 0;
	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buf, 1)))
		if (buf[0] == '\n')
			count++;
	close(fd);
	return (count);
}

t_dict *parse(char *s)
{
	char	*str;
	int		len;
	int		i;
	int		j;
	t_dict	*dict;

	len = 0;
/*	while ((ret = read(fd, str, BUF_SIZE)))
	{
		str[ret] = '\0';
		if (str[0] == '\n')
			len++;
	}*/
	str = ft_read(s);
	len = count_line(s);
	if (!(dict = (t_dict*)malloc(sizeof(t_dict) * (len + 2))))
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		dict[j].number = ft_mystrdup(str + i, " :");
		dict[j].len = ft_strlen(dict[j].number);
		i += ft_strlen(dict[j].number);
		while (str[i] == ' ') 
			i++;
		if (str[i] != ':')
			return (0);
		i++;
		while (str[i] == ' ') 
			i++;
		dict[j].str = ft_mystrdup(str + i, "\n");
		i += ft_strlen(dict[j].str) + 1;
		j++;
	}
	dict[j].len = 0;
	return (dict);
}
