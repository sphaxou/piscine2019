/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:50:06 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/10 18:28:28 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_sep(char c, char *sep)
{
	int		i;

	i = 0;
	while (sep[i])
		if (c == sep[i++])
			return (1);
	return (0);
}

int		ft_strlen_sep(char *s, char *sep)
{
	int		i;

	i = 0;
	while (s[i] && (!is_in_sep(s[i], sep)))
		i++;
	return (i);
}

int		count_str(char *str, char *sep)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_in_sep(str[i], sep))
			i++;
		count++;
		while (str[i] && !(is_in_sep(str[i], sep)))
			i++;
	}
	return (count);
}

char	*assign_res(char *str, char *sep)
{
	int		i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen_sep(str, sep) + 1))))
		return (NULL);
	i = 0;
	while (str[i] && !(is_in_sep(str[i], sep)))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *sep)
{
	int		i;
	char	**res;
	int		j;

	if (!(res = (char **)malloc(sizeof(char *) * (count_str(str, sep) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	res[0] = NULL;
	while (str[i])
	{
		while (str[i] && is_in_sep(str[i], sep))
			i++;
		if (str[i])
			res[j++] = assign_res(str + i, sep);
		while (str[i] && !(is_in_sep(str[i], sep)))
			i++;
	}
	res[j] = NULL;
	return (res);
}
