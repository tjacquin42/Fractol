/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:55:20 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/23 18:31:33 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int		rng;

	rng = 0;
	while (dest[rng])
		rng++;
	while (*src && n--)
	{
		dest[rng++] = *src;
		src++;
	}
	dest[rng] = '\0';
	return (dest);
}
