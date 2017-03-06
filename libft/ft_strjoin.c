/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:14:54 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/24 06:44:55 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		rng;
	int		size;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	rng = 0;
	size = ft_strlen(s1);
	size = size + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (*s1)
	{
		dest[rng++] = *s1;
		s1++;
	}
	while (*s2)
	{
		dest[rng++] = *s2;
		s2++;
	}
	dest[rng] = '\0';
	return (dest);
}
