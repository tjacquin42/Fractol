/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ship.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:49:40 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/10 01:22:39 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burning_ship(t_fol *s)
{
	int i;

	s->x = 0;
	while (++s->x < s->img_x)
	{
		s->y = 0;
		while (++s->y < s->img_y)
		{
			s->z_i = 0;
			s->z_r = 0;
			i = 0;
			s->c_r = s->x / s->zoom + (s->ox - ((s->width / 2) / s->zoom));
			s->c_i = s->y / s->zoom + (s->oy - ((s->height / 2) / s->zoom));
			while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter)
			{
				s->tmp = s->z_r;
				s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
				s->z_i = 2 * fabs(s->z_i * s->tmp) + s->c_i;
				i++;
			}
			put_pixel_img(s->x, s->y, i, s);
		}
	}
	return ;
}

void	bbird(t_fol *s)
{
	int i;

	s->x = 0;
	while (++s->x < s->img_x)
	{
		s->y = 0;
		while (++s->y < s->img_y)
		{
			s->z_i = 0;
			s->z_r = 0;
			i = 0;
			s->c_r = s->x / s->zoom + (s->ox - ((s->width / 2) / s->zoom));
			s->c_i = s->y / s->zoom + (s->oy - ((s->height / 2) / s->zoom));
			while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter)
			{
				s->tmp = s->z_r;
				s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
				s->z_i = 2 * fabs(s->z_i) * s->tmp + s->c_i;
				i++;
			}
			put_pixel_img(s->x, s->y, i, s);
		}
	}
	return ;
}

void	cross(t_fol *s)
{
	int i;

	s->x = 0;
	while (++s->x < s->img_x)
	{
		s->y = 0;
		while (++s->y < s->img_y)
		{
			s->z_i = 0;
			s->z_r = 0;
			i = 0;
			s->c_r = s->x / s->zoom + (s->ox - ((s->width / 2) / s->zoom));
			s->c_i = s->y / s->zoom + (s->oy - ((s->height / 2) / s->zoom));
			while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter)
			{
				s->tmp = s->z_r;
				s->z_r = ((s->z_r * s->z_r) -
				(s->z_i * s->z_i * 3) * fabs(s->z_i)) + s->c_r;
				s->z_i = (s->tmp * s->tmp * 3 -
				(s->z_i * s->z_i)) * fabs(s->z_i) + s->c_i;
				i++;
			}
			put_pixel_img(s->x, s->y, i, s);
		}
	}
}
