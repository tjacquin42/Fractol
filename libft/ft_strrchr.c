/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:25:03 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/25 02:43:36 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;

	if (s)
		len = ft_strlen(s) - 1;
	else
		len = 0;
	if (c == '\0')
	{
		len = 0;
		while (s[len])
			len++;
		return ((char *)s + len);
	}
	while (s[len] != c && len > 0)
		len--;
	if (s[len] == c)
		return ((char *)s + len);
	else
		return (NULL);
}
