/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:31:02 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/06 19:03:09 by ghubert          ###   ########.fr       */
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
			s->c_r = s->x / s->zoom + (s->ox - ((s->width / 2) / s->zoom));
			s->c_i = s->y / s->zoom + (s->oy - ((s->height / 2) / s->zoom));
			s->z_r = 0;
			s->z_i = 0;
			i = define_iter(s);
			put_pixel_img(s->x, s->y, i, s);
			s->y++;
 		}
		s->x++;
	}
}
