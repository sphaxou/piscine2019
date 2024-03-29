/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 02:02:22 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 19:56:12 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*s;
	int		sorted;

	i = 0;
	sorted = 0;
	if (!tab[1])
		return ;
	while (!sorted && tab[i + 1])
	{
		sorted = 1;
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			s = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = s;
			sorted = 0;
		}
		i++;
	}
}
