/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:41:41 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/09 22:40:54 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	func_julio(double x, double y, t_fol *s)
{
	int i;

	s->c_r = (s->xzoom - (s->width / 2)) / s->t_zoom;
	s->c_i = (s->yzoom - (s->height / 2)) / s->t_zoom;
	s->z_r = x / s->zoom + (s->ox - ((s->width / 2) / s->zoom));
	s->z_i = y / s->zoom + (s->oy - ((s->width / 2) / s->zoom));
	i = 0;
	while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter)
	{
		s->tmp = s->z_r;
		s->z_r = s->z_r * s->z_r + s->z_i * s->z_i + s->c_r;
		s->z_i = 3 * s->z_i * s->tmp + s->c_i;
		i++;
	}
	if (i == s->iter)
		put_pixel_img(x, y, 1, s);
	else
		put_pixel_img(x, y, i, s);
	return ;
}

void	julio(t_fol *s)
{
	double x;
	double y;

	x = 0;
	while (x < s->img_x)
	{
		y = 0;
		while (y < s->img_y)
		{
			func_julio(x, y, s);
			y++;
		}
		x++;
	}
}

void	func_nin(double x, double y, t_fol *s)
{
	int i;

	s->c_r = (-100 - (s->width / 2)) / 200;
	s->c_i = (500 - (s->height / 2)) / 200;
	s->z_r = x / s->zoom + (s->ox - ((s->width / 2) / s->zoom));
	s->z_i = y / s->zoom + (s->oy - ((s->width / 2) / s->zoom));
	i = 0;
	while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->iter)
	{
		s->tmp = s->z_r;
		s->z_r = s->z_r * s->z_r + s->z_i * s->z_i + s->c_r;
		s->z_i = 2 * s->z_i * s->tmp + s->c_i;
		i++;
	}
	if (i == s->iter)
		put_pixel_img(x, y, 1, s);
	else
		put_pixel_img(x, y, i, s);
	return ;
}

void	nintendo(t_fol *s)
{
	double x;
	double y;

	x = 0;
	while (x < s->img_x)
	{
		y = 0;
		while (y < s->img_y)
		{
			func_nin(x, y, s);
			y++;
		}
		x++;
	}
}
