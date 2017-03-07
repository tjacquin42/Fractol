/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:51:23 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/25 07:19:08 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*scp;
	size_t	i;

	scp = (char *)s;
	i = -1;
	while (++i < n)
		if (*(scp + i) == (char)c)
			return ((void *)scp + i);
	return (NULL);
}
