/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:49:43 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/07 14:06:58 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		esc(t_fol *s)
{
	mlx_clear_window(s->mlx, s->win);
	exit(1);
}

int			key_h(int kc, t_fol *s)
{
	if (kc == KEY_Y || kc == KEY_H || kc == KEY_U || kc == KEY_J ||
			kc == KEY_I || kc == KEY_K)
		adjust_color(s, kc);
	if (kc == ENTER)
		init(s);
	if (kc == ESC)
		esc(s);
	if (kc == KEY_C)
		change_color(s);
	mlx_clear_window(s->mlx, s->win);
	disp_fract(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

int			mouse_h(int butt, int x, int y, t_fol *s)
{
	mlx_clear_window(s->mlx, s->win);
	if (butt == 5 || butt == 1)
		ft_zoom(s, x, y);
	else if (butt == 4 || butt == 2)
		ft_dezoom(s, x, y);
	disp_fract(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

void	init_mlx(t_fol *stk)
{
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->width, stk->height, "Fractol");
	stk->img = mlx_new_image(stk->mlx, stk->width, stk->height);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	disp_fract(stk);
	if (stk->type == 2)
		mlx_hook(stk->win, 6, (1L << 6), &julia_event, stk);
	mlx_key_hook(stk->win, &key_h, stk);
	mlx_mouse_hook(stk->win, &mouse_h, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
}
