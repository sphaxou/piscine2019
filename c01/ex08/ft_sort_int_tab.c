/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:27:29 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/06 17:16:47 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int check;

	check = 1;
	while (check)
	{
		check = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(tab + i, tab + i + 1);
				check = 1;
			}
			i++;
		}
	}
}
