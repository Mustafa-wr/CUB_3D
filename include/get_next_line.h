/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:17:31 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/27 03:11:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# define BUFFER_SIZE 2

char	*get_next_line(int fd);
char	*takel(char	*k);
char	*readk(int fd, char	*all);
char	*the_rest(char *k);
char	*gl_strjoin(char *s1, char *s2);

#endif