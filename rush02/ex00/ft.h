/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 21:12:47 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 20:38:03 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_dict
{
	char	*number;
	int		len;
	char	*str;
}				t_dict;

char			*ft_strcat(char *s1, char *s2);
unsigned int	ft_strlen(char *s);
void			ft_putstr(char *s);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
t_dict			finddict(char *s, int size, int len, t_dict *dict);
t_dict			findexposant(int len, t_dict *dict);
t_dict			findclosest(char *s, int len, t_dict *dict);
void			sortdict(t_dict *dict);
void			printnumber(char *s, int len, t_dict *dict);
t_dict			*parse(char *s);
char			*ft_mystrdup(char *src, char *sep);
int				ft_strcmp(char *s1, char *s2);
int				ft_str10cmp(char *s1, char *s2, int n);
int				ft_abs(int a);
int				ft_checkparams(int ac, char *str);
char			*ft_myatoi(char *str);
void			ft_cleanmem(t_dict **dict);

#endif
