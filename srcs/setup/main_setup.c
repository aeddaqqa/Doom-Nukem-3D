/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:52:53 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/09 12:16:29 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"


void		init_keys(t_doom *d)
{
	d->upt.input.jump = false;
	d->upt.input.crouch = false;
	d->upt.input.look_up = false;
	d->upt.input.mouse_up = false;
	d->upt.input.rot_left = false;
	d->upt.input.rot_right = false;
	d->upt.input.move_back = false;
	d->upt.input.move_forw = false;
	d->upt.input.move_left = false;
	d->upt.input.look_down = false;
	d->upt.input.mouse_down = false;
	d->upt.input.mouse_left = false;
	d->upt.input.move_right = false;
	d->upt.input.mouse_right = false;
}

static void		init(t_doom *d)
{
	d->rend.data = NULL;
	d->sdl.win_ptr = NULL;
	d->sdl.ren_ptr = NULL;
	d->sdl.sur_ptr = NULL;
	d->sdl.tex_ptr = NULL;
	init_keys(d);
}

static void			init_sdl(t_sdl *sdl)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->win_ptr = SDL_CreateWindow("Doom Nukem 3D",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	W * 2, H, SDL_WINDOW_SHOWN);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr,SDL_PIXELFORMAT_ARGB8888 
	,SDL_TEXTUREACCESS_STREAMING, W, H);
}

static void			init_player(t_player *p)
{
	p->pos.x = 500;
	p->pos.y = 500;
	p->pa = 0;
	p->fov = 60;
	p->delta.x = cos(p->pa) * 5;
	p->delta.y = sin(p->pa) * 5;
}

void			setup(t_doom *d)
{
	init(d);
	d->rend.data = malloc(4 * W * H);
	init_sdl(&d->sdl);
	////
	load_texture(d);
	d->upt.input.game = true;
	init_player(&d->player);
}
