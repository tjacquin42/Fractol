/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:12:08 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/10 01:24:53 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	disp_fract(t_fol *s)
{
	if (s->type == 1)
		mandelbrot(s);
	if (s->type == 2)
		julia(s);
	if (s->type == 3)
		burning_ship(s);
	if (s->type == 4)
		bbird(s);
	if (s->type == 5)
		cross(s);
	if (s->type == 6)
		julio(s);
	if (s->type == 7)
		nintendo(s);
	if (s->type == 8)
		tricorn(s);
}

void	init2(t_fol *s)
{
	if (s->type == 2 || s->type == 6 || s->type == 7 || s->type == 8)
	{
		s->color = 2;
		s->zoom = 200;
		s->height = 1000;
		s->width = 1000;
		s->img_x = s->width;
		s->img_y = s->height;
		s->ox = 0;
		s->oy = 0;
		s->iter = 50;
	}
	if (s->type == 3 || s->type == 4 || s->type == 5)
	{
		s->color = 3;
		s->zoom = 200;
		s->height = 1000;
		s->width = 1000;
		s->img_x = s->width;
		s->img_y = s->height;
		s->ox = 0;
		s->oy = 0;
		s->iter = 50;
	}
}

void	init(t_fol *s)
{
	s->blok_julia = 0;
	s->zooming = 0;
	if (s->type == 1)
	{
		s->width = 1000;
		s->height = 1000;
		s->color = 1;
		s->zoom = 250;
		s->img_x = s->width;
		s->img_y = s->height;
		s->ox = -0.40;
		s->oy = 0;
		s->iter = 50;
	}
	else
		init2(s);
	change_color(s);
}

void	parce_it(t_fol *stk, char *a)
{
	if (a[0] == 'm' || a[0] == 'M')
		stk->type = 1;
	else if (a[0] == 'j' || a[0] == 'J')
		stk->type = 2;
	else if ((a[0] == 'B' || a[0] == 'b') && (a[1] == 'S' || a[1] == 's'))
		stk->type = 3;
	else if ((a[0] == 'B' || a[0] == 'b') && (a[1] == 'B' || a[1] == 'b'))
		stk->type = 4;
	else if (a[0] == 'C' || a[0] == 'c')
		stk->type = 5;
	else if ((a[0] == 'J' || a[0] == 'j') && (a[1] == 'o' || a[1] == 'O'))
		stk->type = 6;
	else if (a[0] == 'N' || a[0] == 'n')
		stk->type = 7;
	else if (a[0] == 'T' || a[0] == 't')
		stk->type = 8;
	else
		stk->type = 0;
}

int		main(int ac, char **av)
{
	t_fol *stk;

	if (!(stk = (t_fol*)malloc(sizeof(t_fol))))
		return (0);
	if (ac == 1)
		stk->type = 1;
	else if (ac == 2)
		parce_it(stk, av[1]);
	else
		return (usage_error());
	if (stk->type == 0)
		return (usage_error());
	stk->hide = 0;
	init(stk);
	init_mlx(stk);
	return (0);
}
