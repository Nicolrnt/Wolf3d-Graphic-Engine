/*
** my_mini_map.c for  in /home/nico_lrnt/bootstrap/bswolf
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Fri Dec 16 11:42:09 2016 nico_lrnt
** Last update Sat Jan 14 21:39:39 2017 nico_lrnt
*/

#include "include/structure.h"
#include "include/prototype.h"
#include "include/my.h"

void		put_target(t_map *my_map)
{
  int		x;
  int		y;

  x = WIDTH / 2;
  y = HEIGHT / 2 - 25;
  while (x++ < (WIDTH / 2 + 25) && y++ < (HEIGHT / 2))
    my_put_pixel(my_map->buffer, x, y, sfRed);
  while (x-- > (WIDTH / 2) && y++ < (HEIGHT / 2 + 25))
    my_put_pixel(my_map->buffer, x, y, sfRed);
  while (x-- > (WIDTH / 2 - 25) && y-- > (HEIGHT / 2))
    my_put_pixel(my_map->buffer, x, y, sfRed);
  while (x++ < (WIDTH / 2) && y-- > (HEIGHT / 2 - 25))
    my_put_pixel(my_map->buffer, x, y, sfRed);
  while (y++ < (HEIGHT / 2 + 25))
    my_put_pixel(my_map->buffer, x - 1, y, sfRed);
  while (x-- > (WIDTH / 2 - 25) && y-- > (HEIGHT / 2));
  while (x++ < (WIDTH / 2 + 25))
    my_put_pixel(my_map->buffer, x, y, sfRed);
}

void		put_perso(t_map *my_map, t_player *player)
{
  int		x;
  int		y;

  y = (player->y * my_map->size_line / WIDTH) + my_map->size_line + 45;
  while (y < (player->y * my_map->size_line / WIDTH) + my_map->size_line + 55)
    {
      x = (player->x * my_map->size_colon / WIDTH) + my_map->size_line - 5;
      while (x < (player->x * my_map->size_colon / WIDTH) + SIZE_LINE + 5)
	{
	  my_put_pixel(my_map->buffer, x, y, sfMagenta);
	  x++;
	}
      y++;
    }
}

void		find_perso(t_map *my_map, t_player *player)
{
  int		i;

  i = 0;
  while (my_map->file[i] != '0')
    i++;
  my_map->perso_x = i % my_map->colon;
  my_map->perso_y = i / my_map->colon;
  my_map->perso_x = my_map->perso_x * my_map->size_line;
  my_map->perso_y = my_map->perso_y * my_map->size_line + 50;
  player->x = (i % my_map->colon - 1) * WIDTH;
  player->y = (i / my_map->colon - 1) * WIDTH;
}

void		draw_square(t_map *my_map, sfColor color, int k, int j)
{
  int		x;
  int		y;

  y = 0;
  while (y < my_map->size_line)
    {
      x = 0;
      while (x < my_map->size_colon)
	{
	  my_put_pixel((*my_map).buffer, MAP_X, MAP_Y, color);
	  x++;
	}
      y++;
    }
}

void		my_mini_map(t_map *my_map, t_player *player)
{
  sfColor	Gray;
  int		j;
  int		k;

  gray_it(&Gray, 1);
  my_map->size_line = WIDTH / 5 / my_map->colon;
  my_map->size_colon = WIDTH / 5 / my_map->line;
  k = -1;
  while (++k < my_map->line)
    {
      j = -1;
      while (++j < my_map->colon)
	{
	  my_map->tab[k][j] == 0 ? draw_square(my_map, sfBlack, k, j) : 0;
	  my_map->tab[k][j] == 1 ? draw_square(my_map, sfWhite, k, j) : 0;
	  my_map->tab[k][j] == 2 ? draw_square(my_map, sfWhite, k, j) : 0;
	  my_map->tab[k][j] == 3 ? draw_square(my_map, sfWhite, k, j) : 0;
	  my_map->tab[k][j] == 4 ? draw_square(my_map, sfMagenta, k, j) : 0;
	  my_map->tab[k][j] == 5 ? draw_square(my_map, Gray, k, j) : 0;
	  my_map->tab[k][j] == 6 ? draw_square(my_map, Gray, k, j) : 0;
	  my_map->tab[k][j] == 7 ? draw_square(my_map, sfRed, k, j) : 0;
	}
    }
  put_perso(my_map, player);
  put_target(my_map);
}
