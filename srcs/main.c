/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:12:08 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/03 17:55:01 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
void	disp_fract(t_fol *s)
{
	if (s->type == 1)
		mandelbrot(s);
}

void	init_fract(t_fol *s)
{
	if (s->type == 1)
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
	if (s->type == 3)
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

void	arg_m(t_fol *stk, char *arg)
{
	if ((arg[1] == 'a' || arg[1] == 'A') && (arg[2] == 'n' || arg[2] == 'N') &&
			(arg[3] == 'd' || arg[3] == 'D') && (arg[4] == 'e' || arg[4] == 'E'
				) && (arg[5] == 'l' || arg[5] == 'L') && (arg[6] == 'b' || arg[6
					] == 'B') && (arg[7] == 'r' || arg[7] == 'R') && (arg[8]
						== 'o' || arg[8] == 'O') && (arg[9] == 't' || arg[9]
							== 'T'))
		stk->type = 1;
	else
		stk->type = 0;
}

void	parce_it(t_fol *stk, char *arg)
{
	if (arg[0] == 'm' || arg[0] == 'M')
		arg_m(stk, arg);
}

int		main(int ac, char **av)
{
	t_fol *stk;

	if (!(stk = (t_fol*)malloc(sizeof(t_fol))))
		return (0);
	stk->check = 4;
	if (ac == 1)
		stk->type = 1;
	if (ac == 2)
		parce_it(stk, av[1]);
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, 1000, 800, "Fractol");
	stk->img = mlx_new_image(stk->mlx, 1000, 600);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	init_fract(stk);
	disp_fract(stk);
	mlx_key_hook(stk->win, &key_h, stk);
	mlx_mouse_hook(stk->win, &mouse_h, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
	return (0);
}
