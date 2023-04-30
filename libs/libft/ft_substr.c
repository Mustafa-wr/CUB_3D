/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:39:47 by bammar            #+#    #+#             */
/*   Updated: 2023/05/01 02:13:07 by mradwan          ###   ########.fr       */
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

char	*my_substr(char const *s, int start, int end)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	if (start > end || start >= (int)ft_strlen(s) || end < 0)
		return (ft_strdup(""));
	if (end >= (int)ft_strlen(s))
		end = ft_strlen(s) - 1;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i <= end)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
