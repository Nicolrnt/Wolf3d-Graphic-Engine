/*
** other_key.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Wed Jan  4 13:50:22 2017 nico_lrnt
** Last update Thu Jan 12 13:42:36 2017 nico_lrnt
*/

#include "structure.h"
#include "prototype.h"
#include "my.h"

void		change_center(t_map *my_map, t_player *player, int key)
{
  my_map->i = 0;
  if (key == 0)
    {
      while (my_map->i++ < 10)
	{
	  my_map->center += 10;
	  check_wall(my_map, player);
	  display_window(my_map, player);
	}
      while (my_map->i-- > 0)
	{
	  my_map->center -= 10;
	  check_wall(my_map, player);
	  display_window(my_map, player);
	}
    }
  else if (key == 1)
    my_map->center -= 50;
  else if (key == 3)
    my_map->center += 50;
  else
    my_map->center = 0;
  check_wall(my_map, player);
  display_window(my_map, player);
}

void		check_key_move(t_map *my_map, t_player *player, int key)
{
  if (key == 1)
    {
      player->x += cos((player->angle - 90) * DEG) * (player->speed / 2);
      player->y += sin((player->angle - 90) * DEG) * (player->speed / 2);
    }
  else
    {
      player->x += cos((player->angle + 90) * DEG) * (player->speed / 2);
      player->y += sin((player->angle + 90) * DEG) * (player->speed / 2);
    }
  check_wall(my_map, player);
  display_window(my_map, player);
}

void		change_weapon(t_map *my_map, t_player *player, int key)
{
  if (key == 0)
    player->weapon = 0;
  if (key == 2)
    player->weapon = 2;
  if (key == 3)
    player->weapon = 3;
  if (key == 4)
    player->weapon = 4;
  display_window(my_map, player);
}

void		shoot(t_map *my_map, t_player *player)
{
  if (player->weapon == 0 && player->mode == 0)
    {
      player->weapon = 1;
      display_window(my_map, player);
      sfMusic_play(player->music_gun);
      usleep(300000);
      player->weapon = 0;
      display_window(my_map, player);
    }
  else if (player->weapon == 0 && player->mode == 1)
    sfMusic_play(player->music_portal);
  else if (player->weapon == 2 && player->mode == 0)
    sfMusic_play(player->music_knife);
  else if (player->weapon == 2 && player->mode == 1)
    sfMusic_play(player->music_repare_tool);
  else if (player->weapon == 3 && player->mode == 1)
    sfMusic_play(player->music_hammer);
  player->weapon != 0 ? usleep(300000) : 0;
  check_enemy(my_map, player);
}
