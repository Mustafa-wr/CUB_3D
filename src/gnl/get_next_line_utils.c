/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:57:51 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/27 03:10:29 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// this function for join the last string with the new one by malloc
// and free the old string because we did not need it.

char	*gl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = -1;
	j = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (join == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			join[i] = s1[i];
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[(ft_strlen(s1) + ft_strlen(s2))] = '\0';
	free(s1);
	return (join);
}

// takel -> this function for take the line clearly with the new line
// allocate for new string + value of "null" & "newline" ("i + 2") ...
// .after that copying the string whithout "null" then close it with '\0'...
// ...when find a new line after copying it

char	*takel(char *k)
{
	int		i;
	char	*line;

	i = 0;
	if (k[i] == '\0')
		return (NULL);
	while (k[i] != '\0' && k[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (k[i] != '\0' && k[i] != '\n')
	{
		line[i] = k[i];
		i++;
	}
	if (k[i] == '\n')
	{
		line[i] = k[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
