/*
** check_key.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Fri Dec 16 14:54:49 2016 nico_lrnt
** Last update Thu Jan 12 12:43:52 2017 nico_lrnt
*/

#include "include/structure.h"
#include "include/prototype.h"
#include "include/my.h"

void		check_key_up(t_map *my_map, t_player *player)
{
  int		x;
  int		y;

  x = player->x + cos(player->angle * DEG) * player->speed;
  y = player->y + sin(player->angle * DEG) * player->speed;
  if (MOVE == 0 || MOVE == 2 || MOVE == 3)
    {
      player->x = x;
      player->y = y;
    }
  else
    {
      if (player->angle > 45 && player->angle < 135 && SLIDE_V != 1)
	player->y = y;
      else if (player->angle > 135 && player->angle < 225 && SLIDE_H != 1)
	player->x = x;
      else if (player->angle > 225 && player->angle < 315 && SLIDE_V != 1)
	player->y = y;
      else if ((player->angle > 315 || player->angle < 45) && SLIDE_H != 1)
	player->x = x;
    }
  check_teleport(my_map, player);
  check_wall(my_map, player);
  display_window(my_map, player);
}

void		check_key_left(t_map *my_map, t_player *player)
{
  player->angle = player->angle - 3;
  if (player->angle < 0)
    player->angle += 360;
  check_wall(my_map, player);
  display_window(my_map, player);
}

void		check_key_right(t_map *my_map, t_player *player)
{
  player->angle = player->angle + 3;
  if (player->angle >= 360)
    player->angle -= 360;
  check_wall(my_map, player);
  display_window(my_map, player);
}

void		check_key_down(t_map *my_map, t_player *player)
{
  player->x -= cos(player->angle * DEG) * player->speed;
  player->y -= sin(player->angle * DEG) * player->speed;
  check_wall(my_map, player);
  display_window(my_map, player);
}

void		check_key(t_map *my_map, t_player *player)
{
  KEY(sfKeyUp) == sfTrue ? check_key_up(my_map, player) : 0;
  KEY(sfKeyZ) == sfTrue ? check_key_up(my_map, player) : 0;
  KEY(sfKeyLeft) == sfTrue ? check_key_left(my_map, player) : 0;
  KEY(sfKeyQ) == sfTrue ? check_key_move(my_map, player, 1) : 0;
  KEY(sfKeyRight) == sfTrue ? check_key_right(my_map, player) : 0;
  KEY(sfKeyD) == sfTrue ? check_key_move(my_map, player, 2) : 0;
  KEY(sfKeyDown) == sfTrue ? check_key_down(my_map, player) : 0;
  KEY(sfKeyS) == sfTrue ? check_key_down(my_map, player) : 0;
  KEY(sfKeySpace) == sfTrue ? change_center(my_map, player, 0) : 0;
  KEY(sfKeyW) == sfTrue ? change_center(my_map, player, 1) : 0;
  KEY(sfKeyX) == sfTrue ? change_center(my_map, player, 2) : 0;
  KEY(sfKeyC) == sfTrue ? change_center(my_map, player, 3) : 0;
  if (KEY(sfKeyO) == sfTrue)
    (player->speed + 50 < 500) ? (player->speed += 50) : 0;
  if (KEY(sfKeyL) == sfTrue)
    (player->speed - 50 > 0) ? (player->speed -= 50) : 0;
  KEY(sfKeyNum1) == sfTrue ? change_weapon(my_map, player, 0) : 0;
  KEY(sfKeyNum2) == sfTrue ? change_weapon(my_map, player, 2) : 0;
  KEY(sfKeyNum3) == sfTrue ? change_weapon(my_map, player, 3) : 0;
  KEY(sfKeyNum4) == sfTrue ? change_weapon(my_map, player, 4) : 0;
  KEY(sfKeyEscape) == sfTrue ? sfRenderWindow_close(my_map->window) : 0;
  KEY(sfKeyM) == sfTrue ? sfMusic_play(player->music_game) : 0;
  KEY(sfKeyE) == sfTrue ? shoot(my_map, player) : 0;
  KEY(sfKeyR) == sfTrue ? wolf3d(my_map, player, my_map->ac, my_map->av) : 0;
}
