/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:43:51 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/26 14:08:41 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *s)
{
	int	res;
	int i;
	int neg;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\f' ||
			s[i] == '\r' || s[i] == '\v')
		i++;
	neg = 1;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -neg;
		i++;
	}
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * neg);
}

int	ft_atoi_len(char *s, int len)
{
	int	res;
	int i;
	int neg;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\f' ||
			s[i] == '\r' || s[i] == '\v')
		i++;
	neg = 1;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -neg;
		i++;
	}
	res = 0;
	while (s[i] >= '0' && s[i] <= '9' && i < len)
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * neg);
}
