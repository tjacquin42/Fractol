/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:12:21 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/25 05:24:44 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int			rng;

	rng = 0;
	while (s1[rng] == s2[rng] && s1[rng] != '\0' && s2[rng] != '\0')
		rng++;
	return (*((unsigned char *)s1 + rng) - *((unsigned char *)s2 + rng));
}
