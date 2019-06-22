/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:28:25 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/20 18:24:47 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s);
int		checkbase(char *s);

int		get_len(int nb, char *b)
{
	int		len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb /= ft_strlen(b);
	}
	return (len);
}

char	*ft_itoa_base(int nb, char *b)
{
	char	*res;
	int		i;
	int		len;

	len = get_len(nb, b);
	if (!(res = (char *)malloc(sizeof(char) * (1 + len))))
		return (NULL);
	i = (nb > 0 ? nb : -nb);
	res[len--] = '\0';
	if (nb == -2147483648)
	{
		res[len--] = b[(i - ft_strlen(b)) % ft_strlen(b)];
		i = i / ft_strlen(b) * -1;
	}
	if (nb < 0)
		res[0] = '-';
	if (nb == 0)
		res[0] = b[0];
	while (i)
	{
		res[len--] = b[i % ft_strlen(b)];
		i /= ft_strlen(b);
	}
	return (res);
}
