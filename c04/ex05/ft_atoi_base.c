/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:57:30 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/08 20:47:05 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_value(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	checkbase(char *s)
{
	int i;
	int j;

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
