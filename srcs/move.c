/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:38:36 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/10 01:19:09 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_put_commands(t_fol *s)
{
	if (s->hide == 0)
	{
		mlx_string_put(s->mlx, s->win, 10, 10, 0xffffff,
				"Move= [Arrows]");
		mlx_string_put(s->mlx, s->win, 10, 25, 0xffffff,
				"Change palette= [C]");
		mlx_string_put(s->mlx, s->win, 10, 40, 0xffffff,
				"Next fractal= [Tab]");
		mlx_string_put(s->mlx, s->win, 10, 55, 0xffffff,
				"Reset current= [Enter]");
		mlx_string_put(s->mlx, s->win, 10, 70, 0xffffff,
				"Red +/- = [Y]/[H], Green +/- = [U]/[J], Blue +/- = [I]/[K]");
		mlx_string_put(s->mlx, s->win, 10, 85, 0xffffff,
				"LockOn fractal= [Space]");
		mlx_string_put(s->mlx, s->win, 10, 100, 0xffffff,
				"Exit= [Esc]");
		mlx_string_put(s->mlx, s->win, 10, 115, 0xffffff,
				"Hide help= [Ctrl]");
	}
}

void			ft_zoom(t_fol *s, int x, int y)
{
	double tmpx;
	double tmpy;

	if (x > 0 && y > 0)
	{
		s->zooming = 1;
		tmpx = ((x - s->width / 2) / s->zoom) + s->ox;
		tmpy = ((y - s->height / 2) / s->zoom) + s->oy;
		s->zoom *= 1.3;
		s->ox = tmpx - ((x - s->width / 2) / s->zoom);
		s->oy = tmpy - ((y - s->height / 2) / s->zoom);
		s->iter *= 1.15;
	}
}

void			ft_dezoom(t_fol *s, int x, int y)
{
	double tmpx;
	double tmpy;

	if (x > 0 && y > 0 && s->zooming == 1)
	{
		tmpx = ((x - s->width / 2) / s->zoom) + s->ox;
		tmpy = ((y - s->height / 2) / s->zoom) + s->oy;
		s->zoom /= 1.3;
		s->iter /= 1.15;
		s->ox = tmpx - ((x - s->width / 2) / s->zoom);
		s->oy = tmpy - ((y - s->height / 2) / s->zoom);
	}
}
