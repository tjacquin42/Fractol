/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:56:12 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 10:20:01 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		rng;

	rng = 0;
	while (s1[rng] == s2[rng] && s1[rng] != '\0' && rng < n)
		rng++;
	if (rng < n)
		return (*((unsigned char *)s1 + rng) - *((unsigned char *)s2 + rng));
	return (0);
}
