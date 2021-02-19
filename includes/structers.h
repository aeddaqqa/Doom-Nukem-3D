/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:11:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/09 09:52:02 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTERS_H
#define STRUCTERS_H

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vect3;

typedef t_vect3 	t_point;

typedef struct		s_input
{
	bool			game;
	bool			jump;
	bool			crouch;
	bool			look_up;
	bool			look_down;
	bool			rot_left;
	bool			rot_right;
	bool			move_left;
	bool			move_right;
	bool			move_forw;
	bool			move_back;
	bool			mouse_up;
	bool			mouse_down;
	bool			mouse_right;
	bool			mouse_left;
}					t_input;

typedef struct		s_sdl
{
	SDL_Window		*win_ptr;
	SDL_Texture		*tex_ptr;
	SDL_Renderer	*ren_ptr;
	SDL_Surface		*sur_ptr;
	SDL_Surface		*Wall;
	SDL_Surface		*Sky;
	SDL_Surface		*Floor;
	SDL_Texture		*test;
	unsigned int	*Wall_pixels;
	unsigned int	*Sky_pixels;
	unsigned int	*Floor_pixels;
}					t_sdl;

typedef struct		s_player
{
	t_vect3		pos;
	t_vect3		direction;
	t_vect3		delta;
	double		fov;
	double		pa;
}					t_player;


typedef struct		s_inter
{
	int			i;
	int			mx;
	int			my;
	int			mp;
	double		step_x;
	double		step_y;
	double		delta_x;
	double		delta_y;
	double		a_tan;
}					t_inter;


typedef struct		s_hit
{
	t_point		p;
	int			map_xy;
	double		dist;
}					t_hit;

typedef struct		s_raycasting
{
	double			ray_angle;
	double			angle_d;
	double			inc;
	int				x;
	int				line_h;
	int				line_o;
	t_hit			hit;
}					t_raycasting;

typedef struct		s_render
{
	int				*data;
}					t_render;

typedef struct		s_update
{
	t_input			input;
	char			*key_table;
}					t_update;



typedef struct		s_doom
{
	t_sdl			sdl;
	t_render		rend;
	t_update		upt;
	t_player		player;
}					t_doom;


#endif
