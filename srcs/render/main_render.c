/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:25:30 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/09 12:16:09 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void				render(t_doom *d)
{
	SDL_RenderClear(d->sdl.ren_ptr);
	SDL_UpdateTexture(d->sdl.tex_ptr, NULL, d->rend.data, W * 4);
	SDL_RenderCopy(d->sdl.ren_ptr, d->sdl.tex_ptr, NULL, NULL);
	SDL_SetRenderDrawColor(d->sdl.ren_ptr, 255, 255, 255, 0);
	draw_minimap(d);
	SDL_RenderPresent(d->sdl.ren_ptr);
}
