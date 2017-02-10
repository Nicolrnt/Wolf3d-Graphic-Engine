/*
** my_draw_line.c for  in /home/nico_lrnt/Documents/GCP/wireframe
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Thu Dec  8 10:49:04 2016 nico_lrnt
** Last update Sun Dec 11 14:35:37 2016 nico_lrnt
*/

#include "structure.h"
#include "my.h"

void	my_draw_line(t_my_framebuffer *buffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int	dx;
  int	dy;
  int	x;
  int	y;

  dx = to.x - from.x;
  dy = to.y - from.y;
  x = from.x;
  y = from.y;
  if (abs(dx) > abs(dy))
    while (x != to.x)
      {
	y = from.y + dy * (x - from.x) / dx;
	my_put_pixel(buffer, x, y, color);
	to.x > from.x ? x++ : x--;
      }
  else
    while (y != to.y)
      {
	x = from.x + dx * (y - from.y) / dy;
	my_put_pixel(buffer, x, y, color);
	to.y > from.y ? y++ : y--;
      }
}
