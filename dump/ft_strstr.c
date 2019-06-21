/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:44:42 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/08 19:33:11 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

static int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

char			*ft_strstr(char *s, char *find)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!find[i])
		return (s);
	while (s[i])
	{
		if (!(ft_strncmp(s + i, find, ft_strlen(find))))
			return (s + i);
		i++;
	}
	return (NULL);
}
