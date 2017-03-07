/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:12:08 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/07 14:14:41 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
void	disp_fract(t_fol *s)
{
	if (s->type == 1)
		mandelbrot(s);
	if (s->type == 2)
		julia(s);
}

void	init2(t_fol *s)
{
	if (s->type == 2)
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
}

void	init(t_fol *s)
{
	s->blok_julia = 0;
	s->zooming = 0;
	if (s->type == 1)
	{
		s->width = 1000;
		s->height = 600;
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

void	parce_it(t_fol *stk, char *arg)
{
	if (arg[0] == 'm' || arg[0] == 'M')
		stk->type = 1;
	if (arg[0] == 'j' || arg[0] == 'J')
		stk->type = 2;
}

int		main(int ac, char **av)
{
	t_fol *stk;

	if (!(stk = (t_fol*)malloc(sizeof(t_fol))))
		return (0);
	if (ac == 1)
		stk->type = 1;
	if (ac == 2)
		parce_it(stk, av[1]);
	init(stk);
	init_mlx(stk);
	return (0);
}
