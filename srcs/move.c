/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:38:36 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/07 12:28:44 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_zoom(t_fol *s, int x, int y)
{
	if (x > 0 && y > 0)
	{
		s->zooming = 1;
		s->ox += (x - s->width / 2) / s->zoom;
		s->oy += (y - s->height / 2) / s->zoom;
		s->x1 = x;
		s->y1 = y;
		s->zoom *= 1.3;
		s->iter *= 1.15;
	}
}

void			ft_dezoom(t_fol *s, int x, int y)
{
	if (x > 0 && y > 0 && s->zooming == 1)
	{
		s->ox -= (s->x1 - s->width / 2) / s->zoom;
		s->oy -= (s->y1 - s->width / 2) / s->zoom;
		s->zoom /= 2;
		s->iter /= 1.2;
	}
}
