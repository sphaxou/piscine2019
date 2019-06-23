/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:59:43 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 03:18:08 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_car
{
	char	obs;
	char	plein;
	char	vide;
}				t_car;

void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
int		ft_is_num(char c);
char	**parse(char *file, t_car *car, int *h, int *l);
void	ft_putchar_fd(char c, int fd);
int		bsq(char *file);
int		ft_atoi(char *s);
char	**ft_split(char *s, char *sep);
char	*ft_strcat(char *s1, char *s2);
#endif
