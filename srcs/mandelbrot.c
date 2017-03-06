/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:31:02 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/06 16:42:40 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			define_iter(t_fol *s)
{
	int i;

	i = 0;
	while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter)
	{
		s->tmp = s->z_r;
		s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
		s->z_i = 2 * s->z_i * s->tmp + s->c_i;
		i++;
	}
	return (i);
}

void		mandelbrot(t_fol *s)
{
	int		i;

	s->x = 0;
	while (s->x < s->img_x)
	{
		s->y = 0;
		while (s->y < s->img_y)
		{
			s->c_r = s->x / s->zoom + s->x1;
			s->c_i = s->y / s->zoom + s->y1;
			s->z_r = 0;
			s->z_i = 0;
			i = define_iter(s);
			if (i == s->iter)
			{
				if (s->x < 1000 && s->y < 600)
					*(unsigned *)(s->gda + (s->y * s->szl) +
							(s->x * s->bpx / 8)) = 0x0000000;
			}
			else
			{
				if (s->x < 1000 && s->y < 600)
					*(unsigned *)(s->gda + (s->y * s->szl) +
							(s->x * s->bpx / 8)) = 0x0FF0000;
			}
			s->y++;
 		}
		s->x++;
	}
}
/*
void		init_mandel(t_fol *s)
{
	s->zoom = 300;
	s->img_x = (s->x2 - s->x1) * s->zoom;
	s->img_y = (s->y2 - s->y1) * s->zoom;
	s->x1 = -2.1;
	s->x2 = 1.5;
	s->y1 = -1.0;
	s->y2 = 1.2;
	s->iter = 50;
	ft_putstr("inited\n");
	ft_putnbr(s->img_y);
	mandelbrot(s);
}*/
