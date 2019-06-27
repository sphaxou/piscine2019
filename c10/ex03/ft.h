/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:15:26 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 01:43:07 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int i);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcat(char *s1, char *s2);
void	ft_hexdump(char **av, int option, int printed, int star);
void	print_hex(int i, int j, char *b);
void	print_options(char *s, int i, int j, int size);
void	print_error(char *name, int err);
int		print_line(char *s, int i, int size, int option);
int		petite_etoile(int star);
int		readinput(int option, int star);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strlen(char *s);
void	print_end(int i, int option);

#endif
