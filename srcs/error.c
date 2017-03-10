/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 23:19:15 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/09 23:21:21 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				usage_error(void)
{
	ft_putstr("Usage : ./fillit [fractal_ID]\nFractal_ID :\nMandelbrot");
	ft_putstr(" = M\nJulia = Ju\nBurning Ship = Bs\nBurning Bird = Bb\n");
	ft_putstr("Cross = C\nJulio = Jo\nNintendo = N\nTricorn = T\n");
	return (0);
}
