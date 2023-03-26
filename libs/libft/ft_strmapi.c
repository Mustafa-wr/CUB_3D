/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:36:01 by bammar            #+#    #+#             */
/*   Updated: 2023/03/27 02:51:47 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ss;

	if (!s || !f || ft_strlen(s) == 0)
		return (ft_strdup("\0"));
	ss = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		ss[i] = f(i, s[i]);
		i++;
	}
	ss[i] = 0;
	return ((char *)ss);
}
