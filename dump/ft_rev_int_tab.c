/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:52:04 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/06 21:01:42 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	size--;
	while (i < size)
		ft_swap(tab + i++, tab + size--);
}
