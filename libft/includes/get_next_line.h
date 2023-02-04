/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:50:20 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 23:50:26 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd, int boolean);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_gnl_strchr(char *str, char c);
char	*fill_buffer(char *bufferleft, int fd);
int		count_line(char *str);
char	*cut_line(char *bufferleft);
char	*new_buff(char *bufferleft);

#endif