/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:43:42 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/23 18:26:18 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		rng;

	rng = 0;
	while (dest[rng])
		rng++;
	while (*src)
	{
		dest[rng++] = *src;
		src++;
	}
	dest[rng] = '\0';
	return (dest);
}
