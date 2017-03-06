/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <ghubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:17:39 by ghubert           #+#    #+#             */
/*   Updated: 2016/11/28 09:20:10 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst)
	{
		if (*alst)
		{
			tmp = (*alst)->next;
			ft_lstdelone(alst, del);
			if (tmp)
				ft_lstdel(&tmp, del);
		}
		*alst = NULL;
	}
}
