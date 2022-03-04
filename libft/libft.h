/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:43:38 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 13:45:24 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE	(1)

int		get_next_line(int fd, char **line);
char	**ft_split(char const *str, char c);
int		ft_numb_count(char *str, char c);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
float	ft_module(float i);
float	maximum(float i1, float i2);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *string, int sym);
char	*ft_strdup(const char *str);
char	*ft_strnew(size_t size);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *prefstr, char const *sufstr);

#endif
