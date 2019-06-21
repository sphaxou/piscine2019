/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:00:51 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/06 18:29:21 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_char_is_alpha_num(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'));
}

char		*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && !(ft_char_is_alpha_num(str[i])))
			i++;
		if (str[i] && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] + 'A' - 'a';
			i++;
		while (str[i] && ft_char_is_alpha_num(str[i]))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 'a' - 'A';
			i++;
		}
	}
	return (str);
}
