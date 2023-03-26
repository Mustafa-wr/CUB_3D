/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:39:47 by bammar            #+#    #+#             */
/*   Updated: 2023/03/27 02:52:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;
	size_t	strlen;
	size_t	char_count;

	if (!s || (size_t)start >= ft_strlen((char *)s)
		|| ft_strlen((char *)s) == 0)
		return (ft_strdup("\0"));
	strlen = ft_strlen((char *)s);
	char_count = 0;
	if (len + start < strlen)
		char_count = (len);
	else
		char_count = (strlen - (size_t)start);
	s2 = malloc(char_count + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < char_count)
	{
		s2[i] = s[i + (size_t)start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
