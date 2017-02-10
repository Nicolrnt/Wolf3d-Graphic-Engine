/*
** menu.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Thu Jan  5 18:35:48 2017 nico_lrnt
** Last update Tue Jan 10 20:43:25 2017 nico_lrnt
*/

#include "structure.h"
#include "prototype.h"
#include "my.h"

void		display_screen(t_map *my_map, int key)
{
  sfRenderWindow_clear(my_map->window, sfBlack);
  if (key == 0)
    {
      sfRenderWindow_drawSprite(my_map->window, my_map->menu_1, NULL);
      my_map->menu_state = 0;
    }
  else if (key == 1)
    {
      sfRenderWindow_drawSprite(my_map->window, my_map->menu_2, NULL);
      my_map->menu_state = 1;
    }
  else if (key == 2)
    {
      sfRenderWindow_drawSprite(my_map->window, my_map->menu_3, NULL);
      my_map->menu_state = 2;
    }
  sfRenderWindow_display(my_map->window);
}

void		set_screen(t_map *my_map)
{
  sfVector2f	position;
  sfVector2f	scale;

  my_map->menu_1 = sfSprite_create();
  my_map->menu_2 = sfSprite_create();
  my_map->menu_3 = sfSprite_create();
  my_map->texture_menu_1 = sfTexture_createFromFile(MENU_1, NULL);
  my_map->texture_menu_2 = sfTexture_createFromFile(MENU_2, NULL);
  my_map->texture_menu_3 = sfTexture_createFromFile(MENU_3, NULL);
  sfSprite_setTexture(my_map->menu_1, my_map->texture_menu_1, sfTrue);
  sfSprite_setTexture(my_map->menu_2, my_map->texture_menu_2, sfTrue);
  sfSprite_setTexture(my_map->menu_3, my_map->texture_menu_3, sfTrue);
  position.x = 450;
  position.y = 100;
  scale.x = 2;
  scale.y = 2;
  sfSprite_setPosition(my_map->menu_1, position);
  sfSprite_setPosition(my_map->menu_2, position);
  sfSprite_setPosition(my_map->menu_3, position);
  sfSprite_setScale(my_map->menu_1, scale);
  sfSprite_setScale(my_map->menu_2, scale);
  sfSprite_setScale(my_map->menu_3, scale);
}

void		display_menu(t_map *my_map, t_player *player)
{
  set_screen(my_map);
  display_screen(my_map, 0);
  my_map->menu_state = 0;
  display_screen(my_map, 0);
  while (sfKeyboard_isKeyPressed(sfKeyReturn) == sfFalse)
    {
      if (KEY(sfKeyDown) == sfTrue && MENU == 0)
	display_screen(my_map, 1);
      else if (KEY(sfKeyDown) == sfTrue && MENU == 1)
	display_screen(my_map, 2);
      else if (KEY(sfKeyUp) == sfTrue && MENU == 1)
	display_screen(my_map, 0);
      else if (KEY(sfKeyUp) == sfTrue && MENU == 2)
	display_screen(my_map, 1);
      usleep(50000);
    }
  if (my_map->menu_state == 0)
    player->mode = 0;
  else if (my_map->menu_state == 1)
    player->mode = 1;
  else if (my_map->menu_state == 2)
    {
      sfRenderWindow_destroy(my_map->window);
      exit(0);
    }
}
