/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:52:22 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/12 16:56:05 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int len, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < len)
		f(tab[i++]);
}
