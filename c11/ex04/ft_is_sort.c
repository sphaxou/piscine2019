/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:13:45 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/17 02:45:30 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int len, int (*f)(int, int))
{
	int i;
	int	pos;

	pos = 0;
	i = -1;
	if (len <= 1)
		return (1);
	pos = (f(tab[0], tab[len - 1]) > 0 ? 1 : -1);
	if (pos == 1)
		while (++i < len - 1)
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
	if (pos == -1)
		while (++i < len - 1)
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
	return (1);
}
