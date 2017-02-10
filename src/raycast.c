/*
** raycast.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Fri Dec 16 21:29:15 2016 nico_lrnt
** Last update Sat Jan 14 21:30:25 2017 nico_lrnt
*/

#include "../include/structure.h"
#include "../include/prototype.h"
#include "../include/my.h"

float	raycast(sfVector2f pos, float direction,
		int **map, sfVector2i mapSize)
{
  float	len;
  float	x;
  float	y;

  len = 0;
  x = pos.x;
  y = pos.y;
  while (map[(int)y][(int)x] != 1
	 && x > 0 && x < mapSize.x
	 && y > 0 && y < mapSize.y)
    {
      x += cosf(direction * DEG) * len;
      y += sinf(direction * DEG) * len;
      len += 0.01;
    }
  return (len);
}
