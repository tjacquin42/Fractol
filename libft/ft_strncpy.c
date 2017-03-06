/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:28:36 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/23 20:42:18 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		rng;

	rng = 0;
	while (src[rng] && rng < n)
	{
		dest[rng] = src[rng];
		rng++;
	}
	if (rng < n)
		while (rng < n)
			dest[rng++] = '\0';
	return (dest);
}
