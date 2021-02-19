/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 08:07:46 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/06 09:20:49 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

extern int map[];

void			hori_intersection(t_player *p, t_hit *hori, double ra)
{
	t_inter	t;

	t.i = 0;
	t.a_tan = -1 / tan(ra);
	if (ra > PI)
	{
		t.delta_y = (((int)p->pos.y >> 6) << 6) - 0.0001;
		t.delta_x = (p->pos.y - t.delta_y) * t.a_tan + p->pos.x;
		t.step_y = -64;
		t.step_x = -t.step_y * t.a_tan;
	}
	if (ra < PI)
	{
		t.delta_y = (((int)p->pos.y >> 6) << 6) + 64;
		t.delta_x = (p->pos.y - t.delta_y) * t.a_tan + p->pos.x;
		t.step_y = 64;
		t.step_x = -t.step_y * t.a_tan;
	}
	if (ra == 0 || ra == PI)
	{
		t.delta_x = p->pos.x;
		t.delta_y = p->pos.y;
		t.i = 14;
	}
	while (t.i < 14)
	{
		t.mx = (int)(t.delta_x) >> 6;
		t.my = (int)(t.delta_y) >> 6;
		t.mp = t.my * 14 + t.mx;
		if (t.mp < 196 && t.mp > 0 && map[t.mp])
			break;
		else
		{
			t.delta_x += t.step_x;
			t.delta_y += t.step_y;
			t.i++;
		}
	}
	hori->dist = sqrt((t.delta_x - p->pos.x) * (t.delta_x - p->pos.x) + (t.delta_y - p->pos.y) * (t.delta_y - p->pos.y));
	hori->p.x = t.delta_x;
	hori->p.y = t.delta_y;
	hori->map_xy = t.mp;
}

void		vert_intersection(t_player *p, t_hit *vert, double ra)
{
	t_inter		t;

	t.i = 0;
	t.a_tan = -tan(ra);
	if (ra > P2 && ra < P3)
	{
		t.delta_x = (((int)p->pos.x >> 6) << 6) - 0.0001;
		t.delta_y = (p->pos.x - t.delta_x) * t.a_tan + p->pos.y;
		t.step_x = -64;
		t.step_y = -t.step_x * t.a_tan;
	}
	if (ra < P2 || ra > P3)
	{
		t.delta_x = (((int)p->pos.x >> 6) << 6) + 64;
		t.delta_y = (p->pos.x - t.delta_x) * t.a_tan + p->pos.y;
		t.step_x = 64;
		t.step_y = -t.step_x * t.a_tan;
	}
	if (ra == 0 || ra == PI)
	{
		t.delta_x = p->pos.x;
		t.delta_y = p->pos.y;
		t.i = 14;
	}
	while (t.i < 14)
	{
		t.mx = (int)(t.delta_x) >> 6;
		t.my = (int)(t.delta_y) >> 6;
		t.mp = t.my * 14 + t.mx;
		if (t.mp < 196 && t.mp > 0 && map[t.mp])
			break;
		else
		{
			t.delta_x += t.step_x;
			t.delta_y += t.step_y;
			t.i++;
		}
	}
	vert->dist = sqrt((t.delta_x - p->pos.x) * (t.delta_x - p->pos.x) + (t.delta_y - p->pos.y) * (t.delta_y - p->pos.y));
	vert->p.x = t.delta_x;
	vert->map_xy = t.mp;
	vert->p.y = t.delta_y;
}

t_hit			find_intersection_point(t_player *p, double ra)
{
	t_hit	vert;
	t_hit	hori;

	vert_intersection(p, &vert, ra);
	hori_intersection(p, &hori, ra);
	if (vert.dist < hori.dist)
		return (vert);
	return (hori);
}
