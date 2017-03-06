/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:23:32 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/06 16:26:19 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define ENTER 36
# define ESC 53

typedef struct					s_fol
{
	int							check;
	void						*mlx;
	void						*win;
	void						*img;
	void						*gda;
	int							bpx;
	int							szl;
	int							endl;
	char						*type;
	int							x;
	int							y;
	double						tmp;
	double						zoom;
	double						iter;
	double						x1;
	double						x2;
	double						y1;
	double						y2;
	double						img_x;
	double						img_y;
	double						c_r;
	double						c_i;
	double						z_r;
	double						z_i;
}								t_fol;

int								key_h(int kc, struct s_fol *s);
int								mouse_h(int b, int x, int y, struct s_fol *s);

void							mandelbrot(struct s_fol *stk);
void							init_mandel(t_fol *stk);

void							julia(t_fol *stk);

void							argv_error(t_fol *stk);
void							argv_error(t_fol *stk);

void							ft_zoom(struct s_fol *s, int x, int y);
void							ft_dezoom(struct s_fol *s, int x, int y);

void							init_fract(t_fol *s);
void							find_type(t_fol *stk);

#endif
