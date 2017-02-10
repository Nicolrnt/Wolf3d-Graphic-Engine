/*
** draw_map.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Tue Dec 27 09:46:18 2016 nico_lrnt
** Last update Wed Jan 25 11:44:03 2017 nico_lrnt
*/

#include "include/structure.h"
#include "include/prototype.h"
#include "include/my.h"

void		edit_map(t_map *my_map)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  k = 0;
  while (k < my_map->line)
    {
      j = 0;
      while (j < my_map->colon)
	{
	  if (my_map->file[i] != (my_map->tab[k][j] + 48))
	    my_map->file[i] = my_map->tab[k][j] + 48;
	  i++;
	  j++;
	}
      i++;
      k++;
    }
  close(my_map->fd);
  my_map->fd = open(my_map->av[1], O_RDWR | O_TRUNC);
  write(my_map->fd, my_map->file, i);
}

void		gray_it(sfColor *color, int key)
{
  color->r = 255;
  color->g = 255;
  color->b = 255;
  if (key == 1)
    color->a = 200;
  else
    color->a = 150;
}

void		my_draw_wall(t_map *my_map, int x, float len, int key)
{
  sfColor	Gray_1;
  sfColor	Gray_2;
  int		size;
  int		y;

  gray_it(&Gray_1, 1);
  gray_it(&Gray_2, 2);
  size = (1 / len) * HEIGHT;
  y = (HEIGHT / 2) - (size / 2) + my_map->center;
  my_put_pixel(my_map->buffer, x, y, sfBlack);
  while (y++ < (HEIGHT / 2) + (size / 2) + my_map->center)
    {
      key == 1 ? my_put_pixel(my_map->buffer, x, y, Gray_2) : 0;
      if (key == 2)
	my_put_pixel(my_map->buffer, x, y, (x % 2 == 0 ? sfWhite : sfBlack));
      else if (key == 4)
	my_put_pixel(my_map->buffer, x, y, (x % 5 == 0 ? sfMagenta : sfBlack));
      else if (key == 7)
	my_put_pixel(my_map->buffer, x, y, (x % 5 == 0 ? sfRed : sfBlack));
      else if (key == 5)
	my_put_pixel(my_map->buffer, x, y, (x % 2 == 0 ? Gray_1 : sfBlack));
      else if (key == 6)
	my_put_pixel(my_map->buffer, x, y, (x % 2 == 0 ? Gray_2 : sfBlack));
    }
  my_put_pixel(my_map->buffer, x, y, sfBlack);
}

void	draw_map(t_map *my_map)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 0;
  from.y = 0;
  to.x = WIDTH;
  to.y = 0;
  while (from.y < (HEIGHT / 2 + my_map->center))
    {
      my_draw_line(my_map->buffer, from, to, sfCyan);
      from.y = from.y + 1;
      to.y = to.y + 1;
    }
  while (from.y < HEIGHT)
    {
      my_draw_line(my_map->buffer, from, to, sfGreen);
      from.y = from.y + 1;
      to.y = to.y + 1;
    }
}
