/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2Dmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 08:02:07 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/06 09:32:08 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"


extern int map[];

void				draw_minimap(t_doom *d)
{
	SDL_Rect	srcrect;
	int			i;
	int			j;

	i = 0;
	srcrect.h = BLOCK_SIZE;
	srcrect.w = BLOCK_SIZE;
	while (i < 14)
	{
		j = 0;
		while (j < 14)
		{
			if (i < 15 && j < 15 && map[i + 14 * j])
			{
				srcrect.x = i * BLOCK_SIZE;
				srcrect.y = j * BLOCK_SIZE;
			}
			SDL_SetRenderDrawColor(d->sdl.ren_ptr, 255, 255, 255, 255);
			SDL_RenderFillRect(d->sdl.ren_ptr, &srcrect);
			SDL_SetRenderDrawColor(d->sdl.ren_ptr, 100, 0, 0, 255);
			SDL_RenderDrawLine(d->sdl.ren_ptr, 0, j * 64, 896, j  * 64);
			j++;
		}
		SDL_SetRenderDrawColor(d->sdl.ren_ptr, 100, 0, 0, 255);
		SDL_RenderDrawLine(d->sdl.ren_ptr, i * 64, 0, i * 64, 896);
		i++;
	}
	srcrect.w = 10;
	srcrect.h = 10;
	srcrect.x = d->player.pos.x - 5;
	srcrect.y = d->player.pos.y - 5;
	SDL_SetRenderDrawColor(d->sdl.ren_ptr, 55, 20, 200, 0);
	SDL_RenderFillRect(d->sdl.ren_ptr, &srcrect);
	raycasting(d);
}
