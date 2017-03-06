/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:42:22 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 11:47:57 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srccp;
	char	*dstcp;
	size_t	i;

	i = -1;
	srccp = (char *)src;
	dstcp = (char *)dst;
	if (srccp < dstcp)
		while ((int)(--len) >= 0)
			*(dstcp + len) = *(srccp + len);
	else
		while (++i < len)
			*(dstcp + i) = *(srccp + i);
	return (dst);
}
