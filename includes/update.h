/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 07:52:50 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/06 09:24:21 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
#define UPDATE_H
void			update(t_doom *d);
t_hit			find_intersection_point(t_player *p, double ra);
void			raycasting(t_doom *d);
#endif
