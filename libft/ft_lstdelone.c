/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:04:24 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 09:20:48 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		if (*alst)
		{
			if (del)
				(*del)((**alst).content, (**alst).content_size);
			free(*alst);
		}
		*alst = NULL;
	}
}
