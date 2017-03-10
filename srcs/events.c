/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:49:43 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/10 01:17:28 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		esc(t_fol *s)
{
	mlx_clear_window(s->mlx, s->win);
	exit(1);
}

void		key_h2(int kc, t_fol *s)
{
	if (kc == 126)
		s->oy += 20 / s->zoom;
	else if (kc == 125)
		s->oy -= 20 / s->zoom;
	else if (kc == 124)
		s->ox -= 20 / s->zoom;
	else if (kc == 123)
		s->ox += 20 / s->zoom;
	else if (kc == 256)
		s->hide = (s->hide == 1) ? 0 : 1;
	mlx_clear_window(s->mlx, s->win);
	disp_fract(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	ft_put_commands(s);
}

int			key_h(int kc, t_fol *s)
{
	if (kc == KEY_Y || kc == KEY_H || kc == KEY_U || kc == KEY_J ||
			kc == KEY_I || kc == KEY_K)
		adjust_color(s, kc);
	else if (kc == ENTER)
		init(s);
	else if (kc == SPACE)
		s->blok_julia = (s->blok_julia == 1) ? 0 : 1;
	else if (kc == ESC)
		esc(s);
	else if (kc == KEY_C)
		change_color(s);
	else if (kc == 48)
	{
		if (s->type < 8)
			s->type++;
		else
			s->type = 1;
		init(s);
	}
	key_h2(kc, s);
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
	ft_put_commands(s);
	return (0);
}

void		init_mlx(t_fol *stk)
{
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->width, stk->height, "Fractol");
	stk->img = mlx_new_image(stk->mlx, stk->width, stk->height);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	disp_fract(stk);
	mlx_hook(stk->win, 6, (1L << 6), &julia_event, stk);
	mlx_key_hook(stk->win, &key_h, stk);
	mlx_mouse_hook(stk->win, &mouse_h, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	ft_put_commands(stk);
	mlx_loop(stk->mlx);
}
