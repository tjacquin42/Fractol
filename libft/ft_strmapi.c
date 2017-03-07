/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:24:16 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/24 06:42:44 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*dest;
	int			i;
	int			indx;

	if (!s)
		return (NULL);
	indx = 0;
	i = ft_strlen(s);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
	{
		dest[indx] = f(indx, s[indx]);
		indx++;
	}
	dest[indx] = '\0';
	return (dest);
}
