/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:30:54 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/09 18:31:20 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	func_julia(double x, double y, t_fol *s)
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
		s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
		s->z_i = 2 * s->z_i * s->tmp + s->c_i;
		i++;
	}
	if (i == s->iter)
		put_pixel_img(x, y, 1, s);
	else
		put_pixel_img(x, y, i, s);
	return ;
}

void	julia(t_fol *s)
{
	double x;
	double y;
	
	x = 0;
	while (x < s->img_x)
	{
		y = 0;
		while (y < s->img_y)
		{
			func_julia(x, y, s);
			y++;
		}
		x++;
	}
}

int		julia_event(int x, int y, t_fol *s)
{
	if (s->type == 2 && s->blok_julia == 0)
	{
		s->xzoom = x;
		s->yzoom = y;
		s->t_zoom = s->zoom;
		disp_fract(s);
		mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	}
	return (0);
}
