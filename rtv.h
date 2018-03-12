/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 00:02:16 by anestor           #+#    #+#             */
/*   Updated: 2018/03/11 02:26:51 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# define WIN_H 800
# define WIN_W 1200
# define WIN_POS_X 200
# define WIN_POS_Y 200
# define VIEWPORT_SIZE 1
# define PROJECTION_PLANE_Z 1
# define RGBA(r, g, b, a) (a + (b << 8) + (g << 16) + (a << 24))

typedef struct		s_rgba
{
	uint8_t			a;
	uint8_t			b;
	uint8_t			g;
	uint8_t			r;
}					t_rgba;

typedef struct		s_cam
{
	int				w;
	int				h;
	t_dxyz			v;
	t_dxyz			pos;	
}					t_cam;

typedef struct		s_sphere
{
	t_dxyz			center;
	int				radius;
	int				color;
}					t_sphere;

typedef struct		s_rtv
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	t_cam			cam;
	t_sphere		*spheres;
	int				spheres_n;
	int				*pixels;
}					t_rtv;

#endif
