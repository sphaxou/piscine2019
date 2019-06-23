/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:25:10 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/23 13:59:50 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src, char *stop)
{
	int		i;

	i = 0;
	while (src[i] != stop[0] && src[i] != stop[1])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_mystrdup(char *src, char *sep)
{
	char	*tab;
	int		len;

	len = 0;
	while (src[len] != sep[0] && src[len] != sep[1])
		len++;
	tab = (char*)malloc(sizeof(*src) * (len + 1));
	if (tab != NULL)
	{
		ft_strcpy(tab, src, sep);
		return (tab);
	}
	return (NULL);
}
