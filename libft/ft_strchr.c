/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:18:46 by ghubert           #+#    #+#             */
/*   Updated: 2016/12/12 18:21:30 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		rng;

	rng = 0;
	while (s[rng] != c && s[rng])
		rng++;
	if (s[rng] == c)
		return ((char *)s + rng);
	else
		return (NULL);
}
