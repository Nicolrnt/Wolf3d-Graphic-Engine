/*
** check_wall.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Wed Dec 28 16:25:08 2016 nico_lrnt
** Last update Thu Jan 12 18:00:34 2017 nico_lrnt
*/

#include "include/structure.h"
#include "include/prototype.h"
#include "include/my.h"

void		check_wall(t_map *my_map, t_player *player)
{
  t_wall	wall;

  wall.i = -1;
  draw_map(my_map);
  while (++wall.i < WIDTH)
    {
      wall.len = 1;
      wall.x = player->x + my_map->plan[player->angle][wall.i].x;
      wall.y = player->y + my_map->plan[player->angle][wall.i].y;
      while (wall.x > -WIDTH && wall.x < (WIDTH * (my_map->colon - 1))
	     && wall.y > -WIDTH && wall.y < (WIDTH * (my_map->line - 1))
	     && (WALL == 0 || WALL == 3))
	{
	  wall.x = player->x + wall.len * my_map->plan[player->angle][wall.i].x;
	  wall.y = player->y + wall.len * my_map->plan[player->angle][wall.i].y;
	  wall.len = wall.len + 0.01;
	}
      WALL == 1 ? my_draw_wall(my_map, wall.i, wall.len, 1) : 0;
      WALL == 2 ? my_draw_wall(my_map, wall.i, wall.len, 2) : 0;
      my_draw_wall(my_map, wall.i, wall.len, (WALL4 : WALL7 : 0));
      WALL == 5 ? my_draw_wall(my_map, wall.i, wall.len, 5) : 0;
      WALL == 6 ? my_draw_wall(my_map, wall.i, wall.len, 6) : 0;
    }
  my_mini_map(my_map, player);
}

void		malloc_the_plan(t_map *my_map)
{
  int		i;

  i = 0;
  my_map->plan = malloc(sizeof(sfVector2i*) * 360 + 10);
  while (i <= 360)
    {
      my_map->plan[i] = malloc(sizeof(sfVector2i) * WIDTH);
      i++;
    }
}

void		define_the_plan(t_map *my_map)
{
  t_plan	plan;

  malloc_the_plan(my_map);
  plan.angle = 0;
  while (plan.angle < 360)
    {
      plan.i = 0;
      plan.ray = - (WIDTH / 2);
      plan.x = cos(plan.angle * DEG) * 2000;
      plan.y = sin(plan.angle * DEG) * 2000;
      while (plan.i < WIDTH)
	{
	  my_map->PLAN.x = plan.x;
	  my_map->PLAN.x += cos((plan.angle + 90) * DEG) * plan.ray;
	  my_map->PLAN.y = plan.y;
	  my_map->PLAN.y += sin((plan.angle + 90) * DEG) * plan.ray;
	  plan.i++;
	  plan.ray++;
	}
      plan.angle++;
    }
}
