/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:53:28 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/20 16:20:58 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa_base(int nb, char *b);

int			ft_value(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			checkbase(char *s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '+' ||
				s[i] == '-' || s[i] == '\v' || s[i] == '\r' || s[i] == '\f')
			return (0);
		j = i + 1;
		while (s[j])
			if (s[i] == s[j++])
				return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int			ft_atoi_base(char *s, char *base)
{
	int i;
	int res;
	int neg;

	if (!(checkbase(base)))
		return (0);
	i = 0;
	res = 0;
	neg = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r' ||
			s[i] == '\f' || s[i] == '\v')
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -neg;
		i++;
	}
	while (ft_value(s[i], base) != -1)
	{
		res = res * ft_strlen(base) + ft_value(s[i], base);
		i++;
	}
	return (res * neg);
}

char		*ft_convert_base(char *nbr, char *b1, char *b2)
{
	int		i;
	int		len;
	char	*res;

	len = 1;
	if (!(checkbase(b1)) || !(checkbase(b2)))
		return (NULL);
	i = ft_atoi_base(nbr, b1);
	res = ft_itoa_base(i, b2);
	return (res);
}
