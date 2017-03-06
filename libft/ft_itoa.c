/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:32:32 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 09:15:38 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int nb)
{
	char			*dest;
	int				size;
	unsigned int	n_tmp;

	n_tmp = nb;
	size = ft_nbrlen(nb);
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest[size--] = '\0';
	if (nb == 0)
		dest[0] = '0';
	if (nb < 0)
	{
		dest[0] = '-';
		n_tmp = (n_tmp * -1);
	}
	while (n_tmp >= 1)
	{
		dest[size--] = (n_tmp % 10) + '0';
		n_tmp = n_tmp / 10;
	}
	return (dest);
}
