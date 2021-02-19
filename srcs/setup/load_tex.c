/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:08:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/09 12:16:16 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

void		load_texture(t_doom *d)
{
	if (!(d->sdl.Wall = IMG_Load(WALL)))
	{
		printf("IMG_Load Wall: %s\n", IMG_GetError());
		exit(0);
	}
	if (!(d->sdl.Sky = IMG_Load(SKY)))
	{
		printf("IMG_Load SKY: %s\n", IMG_GetError());
		exit(0);
	}
	if (!(d->sdl.Floor = IMG_Load(FLOOR)))
	{
		printf("IMG_Load Floor: %s\n", IMG_GetError());
		exit(0);
	}
	d->sdl.Wall_pixels = convert_color(d->sdl.Wall->pixels,
			d->sdl.Wall->w,d->sdl.Wall->h,d->sdl.Wall->pitch);
	d->sdl.Sky_pixels = (unsigned int *)d->sdl.Sky->pixels;
	d->sdl.Floor_pixels = (unsigned int *)d->sdl.Floor->pixels;
}

unsigned int     *convert_color(char *pixels, int w, int h , int bbp)
{
    unsigned int *data;
    int i;
    int r;
    int g;
    int b;
    int a;
    int cmp;
    data= malloc(sizeof(int) * w * h);
    i = 0;
    cmp = 0;
    while (i < w * h)
    {
        r = pixels[cmp++] & 255;
        g = pixels[cmp++] & 255;
        b = pixels[cmp++] & 255;
        if (bbp != 3)
            a = pixels[cmp++] & 255;
        data[i] = ((a << 24) | (r << 16) | (g << 8) | b);
        i++;
    }
    return (data);
}
