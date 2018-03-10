/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:51:32 by anestor           #+#    #+#             */
/*   Updated: 2018/03/10 16:44:40 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	rtv_quit(t_rtv *o)
{
	SDL_DestroyRenderer(o->renderer);
	SDL_DestroyWindow(o->win);
	ft_memdel((void **)&o);
	SDL_Quit();
}

int		key_hooks(t_rtv *o)
{
	if (SDL_PollEvent(&o->event))
	{
		if (o->event.type == SDL_KEYDOWN)
		{
			for (int i = 0; i != WIN_W * WIN_H; i++)
			{
				//*(int *)(o->surface->pixels + i * sizeof(int)) = i;
				ft_memset(o->surface->pixels + i * sizeof(int), i, 1);
			}
			if (o->event.key.keysym.sym == SDLK_ESCAPE)
				return (1);
		}
		else if (o->event.type == SDL_KEYUP)
		{
			for (int i = 0; i != WIN_W * WIN_H; i++)
			{
				*(int *)(o->surface->pixels + i * sizeof(int))
					= 0xFFFFFF;
		//:			= RGBA(255, 255, 255, 255);
			//		255 + (255 << 8) + (255 << 16);
			//	ft_memset(o->surface->pixels + i * sizeof(int), 0, 1);
			}
		}	
		else if (o->event.type == SDL_QUIT)
			return (1);
	}
	return (0);
}

t_xyz	ft_xyz(int x, int y, int z)
{
	t_xyz	tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

t_xyz	ft_xyz_minus(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

int		ft_dot(t_xyz a, t_xyz b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_xyz	canvas_to_viewport(int x, int y, t_rtv *o)
{
	t_xyz	tmp;

	tmp.x = x * o->cam.w / WIN_W;
	tmp.y = y * o->cam.h / WIN_H;
	tmp.z = PROJECTION_PLANE_Z;
	return (tmp);
//	return (x * o->cam.w / WIN_W, y * o->cam.h / WIN_H, PROJECTION_PLANE_Z);
}	

void	put_pixel(int x, int y, int color, t_rtv *o)
{
	t_xy	i;

	i.x = x + WIN_W / 2;
	i.y = y + WIN_H / 2;
	if (i.x < 0 || i.y < 0 || i.x >= WIN_W || i.y >= WIN_H)
		return ;
	*(int *)(o->surface->pixels + (i.x + i.y * WIN_W) * sizeof(int)) = color;
}

t_xy	intersect_ray_sphere(t_xyz o, t_xyz d, t_sphere sphere)
{
	t_xyz	c;
	int		r;
	t_xyz	oc;
	t_xyz	i;
	t_xy	t;
	float	discriminant;

	c = sphere.center;
	r = sphere.radius;
	oc = ft_xyz_minus(o, c);
	i.x = ft_dot(d, d);
	i.y = 2 * ft_dot(oc, d);
	i.z = ft_dot(oc, oc) - r * r;
	discriminant = i.y * i.y - 4 * i.x * i.z;
	if (discriminant < 0)
	{
		t.x = INT_MAX;
		t.y = INT_MAX;
	}
	else
	{
		t.x = (-i.y + sqrt(discriminant)) / (2 * i.x);
		t.y = (-i.y - sqrt(discriminant)) / (2 * i.x);
		printf("t.x %d t.y %d o.x %d o.y %d o.z %d d.x %d d.y %d d.z %d sphere.x %d sphere.y %d sphere.z %d\n",
				t.x, t.y, o.x, o.y, o.x, d.x, d.y, d.z,
				sphere.center.x, sphere.center.y, sphere.center.z);
	}
	return (t);
}

int		trace_ray(t_xyz a, t_xyz d, int t_min, int t_max, t_rtv *o)
{
	int			i;
	int			closest_t;
	t_sphere	closest_sphere;
	t_xy		t;

	closest_t = INT_MAX;
	closest_sphere.radius = 0;
	i = 0;
	while (i != o->spheres_n)
	{
		t = intersect_ray_sphere(a, d, o->spheres[i]);
		if (t.x > t_min && t.x < t_max && t.x < closest_t)
		{
			closest_t = t.x;
			closest_sphere = o->spheres[i];
		}
		if (t.y > t_min && t.y < t_max && t.y < closest_t)
		{
			closest_t = t.y;
			closest_sphere = o->spheres[i];
		}
		i++;
	}
	if (closest_sphere.radius == 0)
		return (0xAAAAAA);
	return (closest_sphere.color);
}

void	ray_tracing(t_rtv *o)
{
	t_xy	i;
	t_xyz	vec;
	int		color;

	o->cam.pos = ft_xyz(0, 0, 0);
	i.x = -WIN_W / 2;
	while (i.x != WIN_W / 2)
	{
		i.y = -WIN_H / 2;
		while (i.y != WIN_H / 2)
		{
			vec = canvas_to_viewport(i.x, i.y, o);
			color = trace_ray(o->cam.pos, vec, 1, INT_MAX, o);
			put_pixel(i.x, i.y, 0xFFFFFF, o);
			i.y++;
		}
		i.x++;
	}
}

int		main(void)
{
	t_rtv	*o;

	o = ft_memalloc(sizeof(t_rtv));	
	SDL_Init(SDL_INIT_VIDEO);
	o->win = SDL_CreateWindow("window", WIN_POS_X, WIN_POS_Y, WIN_W, WIN_H, 0);
	o->renderer = SDL_CreateRenderer(o->win, -1, SDL_RENDERER_ACCELERATED);
	o->surface = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32, 0, 0, 0, 0);
	o->cam.h = WIN_H;
	o->cam.w = WIN_W;
	o->spheres_n = 3;
	o->spheres = ft_memalloc(sizeof(t_sphere) * o->spheres_n);
	o->spheres[0].center = ft_xyz(0, -1, 3);
	o->spheres[0].radius = 1;
	o->spheres[0].color = 0xFF0000;
	o->spheres[1].center = ft_xyz(2, 0, 4);
	o->spheres[1].radius = 1;
	o->spheres[1].color = 0x0000FF;
	o->spheres[2].center = ft_xyz(-2, 0, 4);
	o->spheres[2].radius = 1;
	o->spheres[3].color = 0x00FF00;
	while (1)
	{
		if (key_hooks(o) == 1)
			break ;
	//	SDL_SetRenderDrawColor(o->renderer, (i++ % 255), 0, 0, 0);
	//	SDL_RenderClear(o->renderer);
		ray_tracing(o);
		o->texture = SDL_CreateTextureFromSurface(o->renderer, o->surface);
		SDL_RenderCopy(o->renderer, o->texture, NULL, NULL);
		SDL_DestroyTexture(o->texture);
		SDL_RenderPresent(o->renderer);
	}
	rtv_quit(o);
	return (0);
}
