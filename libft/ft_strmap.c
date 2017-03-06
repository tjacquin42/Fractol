/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:47:50 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 11:48:20 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (!new)
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(new + i) = f(*(s + i));
	return (new);
}
