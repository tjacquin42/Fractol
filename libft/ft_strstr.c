/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:30:10 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/25 06:24:05 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	j = 0;
	if (!str && !to_find)
		return ((char *)str + j);
	while (str[j])
	{
		i = 0;
		if (str[j] == to_find[i])
		{
			while (str[j + i] == to_find[i] && str[j + i] && to_find[i])
				i++;
			if (!to_find[i])
				return ((char *)str + j);
		}
		j++;
	}
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	return (NULL);
}
