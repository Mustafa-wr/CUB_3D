/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:18:54 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/30 22:40:46 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	*ft_realloc(void *ptr, size_t size)
// {
// 	void	*new_ptr;

// 	if (ptr == NULL)
// 		return (malloc(size));
//   	if (size == 0) {
//         free(ptr);
//         return NULL;
//     }
// 	new_ptr = malloc(size);
// 	if (new_ptr == NULL)
//         return NULL;
// 	ft_memcpy(new_ptr, ptr, size);
// 	free(ptr);
// 	return (new_ptr);
// }

// static char	*ft_realloc(char *ptr, size_t size)
// {
// 	if (!ptr)
// 		return(malloc(size));
		
// }
#include <malloc.h>
static void *ft_realloc(void *ptr, size_t size)
{
    void *new_ptr;
    size_t copy_size;

    if (ptr == NULL)
        return malloc(size);

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return NULL;

    copy_size = 0;
    char *src = (char *)ptr;
    char *dst = (char *)new_ptr;
    while (copy_size < size && copy_size < malloc_usable_size(ptr)) {
        *dst++ = *src++;
        copy_size++;
    }
    free(ptr);

    return new_ptr;
}



static int	largest_string_length(char **arr)
{
	int	i;
	int	max_len;
	int	len;

	i = 0;
	max_len = 0;
	len = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	put_spaces(char **arr)
{
	int	i;
	int	j;
	int	max_len;
	int	len;
	int	num_spaces;

	max_len = largest_string_length(arr);
	i = 0;
	j = -1;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		num_spaces = max_len - len;
		j = -1;
		if (num_spaces)
		{
			arr[i] = ft_realloc(arr[i], max_len + 1);
			while (++j < num_spaces)
				arr[i][len + j] = ' ';
			arr[i][max_len] = '\0';
		}
		i++;
	}
}
