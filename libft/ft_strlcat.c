/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:08:31 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 11:44:44 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		dest_len;
	size_t		src_len;
	size_t		rng;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	rng = 0;
	if (dest_len + 1 > size)
		return (src_len + size);
	if (dest_len + 1 < size)
	{
		while (dest[rng])
			rng++;
		while (rng < size - 1)
		{
			dest[rng++] = *src;
			src++;
		}
		dest[rng] = '\0';
	}
	return (dest_len + src_len);
}
