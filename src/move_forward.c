/*
** move_forward.c for  in /home/nico_lrnt/bootstrap/bswolf
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Fri Dec 16 10:20:48 2016 nico_lrnt
** Last update Wed Jan 11 15:43:11 2017 nico_lrnt
*/

#include "../include/structure.h"
#include "../include/prototype.h"
#include "../include/my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  pos.x += cosf(direction * DEG) * distance;
  pos.y += sinf(direction * DEG) * distance;
  return (pos);
}
