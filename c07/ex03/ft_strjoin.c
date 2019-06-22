/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 23:19:24 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/13 02:31:36 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		total_len(int size, char **strs, char *sep)
{
	int		i;
	int		count;

	if (size == 0)
		return (1);
	i = 0;
	count = 1 + ((size - 1) * ft_strlen(sep));
	while (i < size)
		count = count + ft_strlen(strs[i++]);
	return (count);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		len;

	len = total_len(size, strs, sep);
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	res[0] = '\0';
	if (size == 0)
		return (res);
	i = 0;
	while (i < size)
	{
		res = ft_strcat(res, strs[i]);
		if (i++ < size - 1)
			res = ft_strcat(res, sep);
	}
	res[len] = '\0';
	return (res);
}
