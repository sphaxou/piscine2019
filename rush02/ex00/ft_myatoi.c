/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 01:22:02 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/23 20:34:09 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

char	*ft_skipzeros(char *str)
{
	unsigned int i;
	unsigned int j;

	if (!(*str))
		return (str);
	i = 0;
	while (str[i] == '0')
		i++;
	j = 0;
	if (i == ft_strlen(str))
	{
		str = "0";
		return (str);
	}
	while (j + i <= ft_strlen(str))
	{
		str[j] = str[j + i];
		j++;
	}
	return (str);
}

char	*ft_myatoi(char *str)
{
	int		len;
	int		i;
	int		j;
	char	sep;

	i = 0;
	len = ft_strlen(str);
	if (!(*str) || !(len > 4 && (str[len - 4] == ' ' || str[len - 4] == ',')))
		return (ft_skipzeros(str));
	sep = str[len - 4];
	while (str[len - ++i])
	{
		if (!(i % 4))
		{
			if (str[len - i] != sep)
			{
				ft_putstr("Error\n");
				return (NULL);
			}
			j = len - i - 1;
			while (str[++j])
				str[j] = str[j + 1];
		}
	}
	return (ft_skipzeros(str));
}
