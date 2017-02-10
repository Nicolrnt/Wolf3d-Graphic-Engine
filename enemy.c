/*
** enemy.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Sun Jan  8 18:35:57 2017 nico_lrnt
** Last update Thu Jan 12 13:52:00 2017 nico_lrnt
*/

#include "structure.h"
#include "prototype.h"
#include "my.h"

void		wich_portal(t_map *my_map, t_player *player, sfVector2i bullet)
{
  if (player->weapon == 0 && player->portal_4 == 0)
    {
      my_map->tab[bullet.y / WIDTH + 1][bullet.x / WIDTH + 1] = 4;
      player->portal_4 = 1;
    }
  else if (player->weapon == 0 && player->portal_7 == 0 && BULLET != 4)
    {
      my_map->tab[bullet.y / WIDTH + 1][bullet.x / WIDTH + 1] = 7;
      player->portal_7 = 1;
    }
}

void		put_wall(t_map *my_map, t_player *player)
{
  sfVector2i	bullet;
  sfVector2i	wall;
  float		len;

  len = 1;
  bullet.x = player->x;
  bullet.y = player->y;
  while (bullet.x > -WIDTH && bullet.y > -WIDTH)
    {
      bullet.x = player->x + len * my_map->plan[player->angle][WIDTH / 2].x;
      bullet.y = player->y + len * my_map->plan[player->angle][WIDTH / 2].y;
      if (BULLET == 0)
	{
	  wall.x = bullet.x;
	  wall.y = bullet.y;
	}
      if (BULLET != 0 && BULLET != 3)
	break;
      len += 0.01;
    }
  if (player->weapon == 2)
    my_map->tab[wall.y / WIDTH + 1][wall.x / WIDTH + 1] = 1;
  else
    wich_portal(my_map, player, bullet);
}

void		wich_wall(t_map *my_map, t_player *player, sfVector2i bullet)
{
  if (BULLET == 1)
    BULLET = 0;
  else if (BULLET == 4)
    {
      BULLET = 1;
      player->portal_4 = 0;
    }
  else if (BULLET == 7)
    {
      BULLET = 1;
      player->portal_7 = 0;
    }
}

void		check_enemy(t_map *my_map, t_player *player)
{
  sfVector2i	bullet;
  float		len;

  len = 1;
  bullet.x = player->x;
  bullet.y = player->y;
  while (bullet.x > -WIDTH && bullet.y > -WIDTH)
    {
      bullet.x = player->x + len * my_map->plan[player->angle][WIDTH / 2].x;
      bullet.y = player->y + len * my_map->plan[player->angle][WIDTH / 2].y;
      if (BULLET != 0 && BULLET != 3)
	break;
      len += 0.01;
    }
  if (BULLET == 6 && player->weapon == 0 && player->mode == 0)
    BULLET = 5;
  else if (BULLET == 5 && (GUN || KNIFE) && player->mode == 0)
    BULLET = 0;
  else if (BULLET != 0 && player->weapon == 3 && player->mode == 1)
    wich_wall(my_map, player, bullet);
  else if (BULLET != 0 && (GUN || REPARE) && player->mode == 1)
    put_wall(my_map, player);
  check_wall(my_map, player);
  display_window(my_map, player);
}
