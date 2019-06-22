/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:24:46 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/09 23:01:57 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}
