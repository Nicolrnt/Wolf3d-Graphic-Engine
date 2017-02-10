/*
** my_put_pixel.c for  in /home/nico_lrnt/Documents/GCP/wolf3d/src
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Thu Dec 15 09:54:42 2016 nico_lrnt
** Last update Sat Jan 14 21:30:48 2017 nico_lrnt
*/

#include "structure.h"
#include "prototype.h"
#include "my.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x, int y, sfColor color)
{
  if (x >= 0 && x < framebuffer->width
      && y >= 0 && y < framebuffer->height)
    {
      framebuffer->pixels[(WIDTH * y + x) * 4 + 0] = color.r;
      framebuffer->pixels[(WIDTH * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(WIDTH * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(WIDTH * y + x) * 4 + 3] = color.a;
    }
}
