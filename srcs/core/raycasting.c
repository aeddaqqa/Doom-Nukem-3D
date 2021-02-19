/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:10:41 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/06 09:49:08 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

extern int map[];

void		protect_a(double *a)
{
	if (*a < 0)
		*a += 2 * PI;
	if (*a > 2 * PI)
		*a -= 2 * PI;
}

void		raycasting(t_doom *d)
{
	t_raycasting	r;

	r.x = 0;
	r.ray_angle = d->player.pa - (d->player.fov / 2.0) * DR;
	protect_a(&r.ray_angle);
	r.inc = d->player.fov * DR / W;
	while (r.x < W)
	{
		r.hit = find_intersection_point(&d->player, r.ray_angle);
		r.angle_d = d->player.pa - r.ray_angle;
		SDL_RenderDrawLine(d->sdl.ren_ptr, d->player.pos.x, d->player.pos.y, r.hit.p.x, r.hit.p.y);
		protect_a(&r.angle_d);
		// printf("%d\n", map[r.hit.map_xy]);
		int v;
		v = BLOCK_SIZE * H;
		r.line_h = v / (r.hit.dist * cos(r.angle_d));
		if (r.line_h >= H)
			r.line_h = H - 1;
		if (r.line_h < 0)
			r.line_h = 0;
		r.line_o = H / 2.0 - r.line_h / 2.0;
		SDL_RenderDrawLine(d->sdl.ren_ptr, r.x + W, r.line_o, r.x + W, r.line_o + r.line_h);
		r.ray_angle += r.inc;
		protect_a(&r.ray_angle);
		r.x++;
	}
}
