/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:13:36 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/06 09:25:11 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void		update(t_doom *d)
{
	if (d->upt.input.move_forw)
	{
		d->player.pos.x += d->player.delta.x * 0.5;  
		d->player.pos.y += d->player.delta.y * 0.5;
	}
	if (d->upt.input.move_back)
	{
		d->player.pos.x -= d->player.delta.x * 0.5;
		d->player.pos.y -= d->player.delta.y * 0.5;
	}
	if (d->upt.input.move_right)
	{
		d->player.pa += 0.01;
		if (d->player.pa > 2 * PI)
			d->player.pa -= 2 *  PI;
		d->player.delta.x = cos(d->player.pa) * 5;
		d->player.delta.y = sin(d->player.pa) * 5;
	}
	if (d->upt.input.move_left)
	{
		d->player.pa -= 0.01;
		if (d->player.pa < 0)
			d->player.pa += 2 *  PI;
		d->player.delta.x = cos(d->player.pa) * 5;
		d->player.delta.y = sin(d->player.pa) * 5;
	}
}
