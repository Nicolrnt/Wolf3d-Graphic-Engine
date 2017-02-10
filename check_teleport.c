/*
** check_teleport.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Thu Jan  5 12:34:39 2017 nico_lrnt
** Last update Tue Jan 10 18:46:39 2017 nico_lrnt
*/

#include "structure.h"
#include "prototype.h"
#include "my.h"

void	find_spot(t_map *my_map, t_player *player, int k, int j)
{
  if (my_map->tab[k - 1][j] == 0 || my_map->tab[k - 1][j] == 3)
    {
      player->x = (j - 1) * WIDTH;
      player->y = (k - 2) * WIDTH;
    }
  else if (my_map->tab[k][j - 1] == 0 || my_map->tab[k][j - 1] == 3)
    {
      player->x = (j - 2) * WIDTH;
      player->y = (k - 1) * WIDTH;
    }
  else if (my_map->tab[k][j + 1] == 0 || my_map->tab[k][j + 1] == 3)
    {
      player->x = (j - 0) * WIDTH;
      player->y = (k - 1) * WIDTH;
    }
  else if (my_map->tab[k + 1][j] == 0 || my_map->tab[k + 1][j] == 3)
    {
      player->x = (j - 1) * WIDTH;
      player->y = (k - 0) * WIDTH;
    }
}

void	check_position(t_map *my_map, t_player *player, int key)
{
  int	j;
  int	k;

  k = 0;
  while (k < my_map->line)
    {
      j = 0;
      while (j < my_map->colon)
	{
	  if (my_map->tab[k][j] == key)
	    find_spot(my_map, player, k, j);
	  j++;
	}
      k++;
    }
}

void	check_teleport(t_map *my_map, t_player *player)
{
  if (POS == 4)
    check_position(my_map, player, 7);
  else if (POS == 7)
    check_position(my_map, player, 4);
}
