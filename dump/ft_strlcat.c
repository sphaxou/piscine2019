/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:25:38 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/08 19:36:57 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int		ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

unsigned int			ft_strlcat(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
		i++;
	while ((i + j) < (n - 1) && s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	if (i < size)
		s1[i + j] = '\0';
	return (n + ft_strlen(s2));
}
