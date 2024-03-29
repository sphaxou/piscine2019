/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:25:38 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/27 12:49:34 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int			ft_strlcat(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s2[k])
		k++;
	while (s1[i] && i < n)
		i++;
	if (!n)
		return (i + k);
	while ((i + j) < (n - 1) && s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	if (i < n)
		s1[i + j] = '\0';
	return (i + k);
}
