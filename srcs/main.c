/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:12:08 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/06 19:06:06 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
void	disp_fract(t_fol *s)
{
	if (s->type == 1)
		mandelbrot(s);
}

void	init(t_fol *s)
{
	s->zooming = 0;
	s->width = 1000;
	s->height = 600;
	if (s->type == 1)
	{
		s->color = 1;
		s->zoom = 250;
		s->img_x = s->width;
		s->img_y = s->height;
		s->ox = -0.40;
		s->oy = 0;
		s->iter = 50;
	}
	change_color(s);
}

void	parce_it(t_fol *stk, char *arg)
{
	if (arg[0] == 'm' || arg[0] == 'M')
		stk->type = 1;
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
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->width, stk->height, "Fractol");
	stk->img = mlx_new_image(stk->mlx, stk->width, stk->height);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	disp_fract(stk);
	mlx_key_hook(stk->win, &key_h, stk);
	mlx_mouse_hook(stk->win, &mouse_h, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
	return (0);
}
