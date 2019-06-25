/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:59:43 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 23:47:08 by vgallois         ###   ########.fr       */
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
typedef struct	s_max
{
	int		value;
	int		i;
	int		j;
	int		h;
	int		l;
}				t_max;
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr(char *s);
int			ft_is_num(char c);
int			**parse(char *file, t_car *car, int *h, int *l);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
int			bsq(char *file);
int			ft_atoi(char *s);
int			**splitint(char *s, t_car car, int h, int l);
char		*ft_strcat(char *s1, char *s2);
void		printtab(int **tab, t_car car, t_max max);
int			ft_strlen(char *s);
char		*ft_strcpy(char *s1, char *s2);
int			zelda(char *s, t_car *car);
void		solve(int **map, int h, int l, t_max *max);
int			readinput(void);

#endif
