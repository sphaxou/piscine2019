/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:11:11 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/08 19:03:32 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	check_base(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s || ft_strlen(s) <= 1)
		return (0);
	while (s[i])
	{
		j = i + 1;
		while (s[j])
			if (s[i] == s[j++])
				return (0);
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void		ft_putnbr_base_nonull(int n, char *base)
{
	int	i;

	i = 0;
	if (!(check_base(base)))
		return ;
	if (n == -2147483648)
	{
		ft_putnbr_base_nonull(n / ft_strlen(base), base);
		ft_putchar(base[(unsigned int)n % ft_strlen(base)]);
	}
	if (n < 0 && n != -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base_nonull(-n, base);
	}
	else
	{
		if (n > 0)
		{
			ft_putnbr_base_nonull(n / ft_strlen(base), base);
			ft_putchar(base[n % ft_strlen(base)]);
		}
	}
}

void		ft_putnbr_base(int n, char *base)
{
	if (n == 0)
		write(1, "0", 1);
	else
		ft_putnbr_base_nonull(n, base);
}
