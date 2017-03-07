/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:11:47 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/07 13:38:44 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	adjust_color(t_fol *s, int k)
{
	if (k == KEY_Y)
		s->clr_r += 10;
	else if (k == KEY_H)
		s->clr_r -= 10;
	else if (k == KEY_U)
		s->clr_g += 10;
	else if (k == KEY_J)
		s->clr_g -= 10;
	else if (k == KEY_I)
		s->clr_b += 10;
	else if (k == KEY_K)
		s->clr_b -= 10;
}

void	change_color(t_fol *s)
{
	
	if (s->color == 1)
	{
		s->clr_r = 255;
		s->clr_g = 0;
		s->clr_b = 0;
		s->color = 2;
	}
	else if (s->color == 2)
	{
		s->clr_r = 100;
		s->clr_g = 255;
		s->clr_b = 180;
		s->color = 3;
	}
	else if (s->color == 3)
	{
		s->clr_r = -20;
		s->clr_g = 220;
		s->clr_b = 90;
		s->color = 1;
	}
}

int	ft_color(int i, t_fol *s)
{
	double c;
	int r;
	int g;
	int b;
	if (i == s->iter)
		return (1);
	c = 0.3 * (i + 1);
	r = cos(c) * s->clr_r + 150;
	g = cos(c) * s->clr_g + 160;
	b = cos(c) * s->clr_b + 170;
	return ((r << 16) + (b << 8) + g);
}

void	put_pixel_img(int x, int y, int i, t_fol *s)
{
	int pl;
	int octet;
	int color;

	color = ft_color(i, s);
	octet = s->bpx / 8;
	pl = (x * (s->bpx / 8)) + (y * s->szl);
	if (x >= 0 && y >= 0 && x < s->width && y < s->height)
		ft_memcpy(&s->gda[pl], &color, octet);
	else if (x == s->width || y == s->height)
		;
	else
		return ;
}
