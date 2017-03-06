/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:54:59 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/24 02:38:09 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		rng;

	rng = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[rng])
	{
		dest[rng] = s[rng];
		rng++;
	}
	dest[rng] = '\0';
	return (dest);
}
