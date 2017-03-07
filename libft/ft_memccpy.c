/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:38:55 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/18 14:06:55 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sour;
	unsigned int	i;

	i = (unsigned char)c;
	dst = (unsigned char *)dest;
	sour = (unsigned char *)src;
	while (n--)
	{
		*dst = *sour;
		dst++;
		if (*sour == i)
			return ((void *)dst);
		sour++;
	}
	return (NULL);
}
