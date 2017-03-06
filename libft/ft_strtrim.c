/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:31:27 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 12:15:08 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		end;
	int		sta;

	if (!s)
		return (NULL);
	sta = 0;
	end = ft_strlen(s);
	while (s[sta] == ' ' || s[sta] == '\n' || s[sta] == '\t')
		sta++;
	if (!s[sta])
		return (ft_strnew(0));
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		end--;
	s = ft_strsub(s, sta, (end - sta));
	return ((char*)s);
}
