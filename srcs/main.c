/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:12:08 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/06 16:49:28 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fract(t_fol *s)
{
	int i;

	i = 0;
	if (s->type[0] == 'm' || s->type[0] == 'M')
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
	}
	if (s->type[0] == 'j' || s->type[0] == 'J')
	{
		s->x1 = -1.5;
		s->x2 = 2;
		s->y1 = -0.9;
		s->y2 = 1.2;
		s->iter = 100;
		s->img_y = 720;
		s->img_x = 810;
		s->zoom = 100;
	}
}

void	find_type(t_fol *stk)
{
	int i;

	i = 0;
	if (stk->type[i] == 'J' || stk->type[i] == 'j')
		return (julia(stk));
	else if (stk->type[i] == 'M' || stk->type[i] == 'm')
		return (mandelbrot(stk));
	argv_error(stk);
}

int		main(int ac, char **av)
{
	t_fol *stk;

	if (!(stk = (t_fol*)malloc(sizeof(t_fol))))
		return (0);
	stk->check = 4;
	if (ac != 2 || ft_strlen(av[1]) > 1)
		argv_error(stk);
	stk->type = av[1];
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, 1000, 800, "Fractol");
	stk->img = mlx_new_image(stk->mlx, 1000, 600);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	init_fract(stk);
	find_type(stk);
	mlx_key_hook(stk->win, &key_h, stk);
	mlx_mouse_hook(stk->win, &mouse_h, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
	return (0);
}
