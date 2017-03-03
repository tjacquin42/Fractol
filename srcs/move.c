/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:38:36 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/03 17:53:11 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_zoom(t_fol *s, int x, int y)
{
	double a;
	double b;
	double sx;
	double sy;

	if (x > 0 && y > 0)
	{
		sx = s->x2 - s->x1;
		sy = s->y2 - s->y1;
		a = s->x1 + ((x * sx) / s->img_x);
		b = s->y1 + ((y * sy) / s->img_y);
		s->x1 = a - sx / s->check;
		s->x2 = a + sx / s->check;
		s->y1 = b - sy / s->check;
		s->y2 = b - sy / s->check;
		s->zoom *= 2;
		s->iter *= 1.2;
	}
		ft_putnbr(s->x1);
		ft_putstr(" x1 | x2 ");
		ft_putnbr(s->x2);
		ft_putchar('\n');
		ft_putnbr(s->y1);
		ft_putstr(" y1 | y2 ");
		ft_putnbr(s->y2);
		ft_putchar('\n');
}

void			ft_dezoom(t_fol *s, int x, int y)
{
	double a;
	double b;
	double sx;
	double sy;

	if (x > 0 && y > 0)
	{
		sx = s->x2 - s->x1;
		sy = s->y2 - s->y1;
		a = s->x1 + x * sx / s->img_x;
		b = s->y1 + y * sy / s->img_y;
		s->x1 = a - sx;
		s->x2 = a + sx;
		s->y1 = b - sy;
		s->y2 = b - sy;
		s->zoom /= 2;
		s->iter /= 1.2;
	}
}
