/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:08:57 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/09 12:10:11 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
#define SETUP_H

void			init_keys(t_doom *d);
void			setup(t_doom *d);
void			load_texture(t_doom *d);
unsigned int     *convert_color(char *pixels, int w, int h , int bbp);
#endif
