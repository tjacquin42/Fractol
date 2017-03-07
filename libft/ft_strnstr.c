/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:50:31 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 11:44:09 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	len_to_find;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(len_to_find = ft_strlen(to_find)))
		return ((char *)str);
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] == to_find[j] && str[i + j])
			j++;
		if (!to_find[j])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
