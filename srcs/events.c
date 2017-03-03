/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:49:43 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/03 17:57:32 by ghubert          ###   ########.fr       */
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
	if (kc == ENTER)
		init_fract(s);
	if (kc == ESC)
		esc(s);
	if (kc == 125)
		s->check += 1;
	if (kc == 126)
		s->check -= 1;
	ft_putnbr(s->check);
	ft_putstr(" = check ^^\n");
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
