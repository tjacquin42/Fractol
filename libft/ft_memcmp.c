/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:00:25 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/25 07:15:08 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cp;
	unsigned char	*s2cp;
	size_t			i;

	i = -1;
	s1cp = (unsigned char *)s1;
	s2cp = (unsigned char *)s2;
	while (++i < n && *(s1cp + i) == *(s2cp + i))
		;
	if (i == n)
		return (0);
	return (*(s1cp + i) - *(s2cp + i));
}
