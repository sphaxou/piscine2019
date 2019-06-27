/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:57:18 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/16 04:38:25 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_atoi(char *s);
void	ft_printtab(int *tab, int s);
int		*ft_parse(char *s, int size);
int		ft_is_whitespace(char c);
int		check_line(int *tab, int x, int size, int *param);
int		check_col(int *tab, int x, int size, int *param);

#endif
