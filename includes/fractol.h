/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:23:32 by ghubert           #+#    #+#             */
/*   Updated: 2017/03/09 18:26:15 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define SPACE 49
# define ESC 53
# define ENTER 36
# define KEY_P 35
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_LS 69
# define KEY_PL 78

typedef struct					s_fol
{
	void						*mlx;
	void						*win;
	void						*img;
	void						*gda;
	int							bpx;
	int							szl;
	int							endl;
	int							type;
	double						ox;
	double						oy;
	int							blok_julia;
	int							x;
	int							y;
	int							width;
	int							height;
	int							julia_w;
	int							julia_h;
	int							zooming;
	int							clr_r;
	int							clr_g;
	int							clr_b;
	int							color;
	double						tmp;
	double						zoom;
	double						t_zoom;
	int							yzoom;
	int							xzoom;
	int							iter;
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

void							burning_ship(struct s_fol *s);
int								key_h(int kc, struct s_fol *s);
int								mouse_h(int b, int x, int y, struct s_fol *s);
void							init(struct s_fol *s);
void							mandelbrot(struct s_fol *stk);
void							disp_fract(struct s_fol *s);
void							ft_zoom(struct s_fol *s, int x, int y);
void							ft_dezoom(struct s_fol *s, int x, int y);
void							put_pixel_img(int x, int y, int i, t_fol *s);
void							change_color(t_fol *s);
void							adjust_color(t_fol *s, int kc);
void							julia(t_fol *s);
int								julia_event(int x, int y, struct s_fol *s);
void							init_mlx(struct s_fol *s);

#endif
