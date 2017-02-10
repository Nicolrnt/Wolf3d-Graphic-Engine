/*
** main.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Mon Dec 12 11:35:02 2016 nico_lrnt
** Last update Sat Jan 14 16:19:51 2017 nico_lrnt
*/

#include "include/structure.h"
#include "include/prototype.h"
#include "include/my.h"

void			destroy_all(t_map *my_map, t_player *player)
{
  sfRenderWindow_destroy(my_map->window);
  sfTexture_destroy(my_map->texture_map);
  sfTexture_destroy(my_map->texture_menu_1);
  sfTexture_destroy(my_map->texture_menu_2);
  sfTexture_destroy(my_map->texture_menu_3);
  sfTexture_destroy(player->texture_gun);
  sfTexture_destroy(player->texture_gun_fire);
  sfTexture_destroy(player->texture_knife);
  sfTexture_destroy(player->texture_repare_tool);
  sfTexture_destroy(player->texture_hammer);
  sfSprite_destroy(my_map->map);
  sfSprite_destroy(my_map->menu_1);
  sfSprite_destroy(my_map->menu_2);
  sfSprite_destroy(my_map->menu_3);
  sfSprite_destroy(player->gun);
  sfSprite_destroy(player->gun_fire);
  sfSprite_destroy(player->knife);
  sfSprite_destroy(player->repare_tool);
  sfSprite_destroy(player->hammer);
  sfMusic_destroy(player->music_gun);
  sfMusic_destroy(player->music_knife);
  sfMusic_destroy(player->music_repare_tool);
  sfMusic_destroy(player->music_hammer);
  sfMusic_destroy(player->music_portal);
  sfMusic_destroy(player->music_game);
}

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit(EXIT_FAILURE);
  return (window);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*frame_buffer;
  int			size;
  int			i;

  size = width * height * 4;
  i = 0;
  frame_buffer = malloc(sizeof(*frame_buffer));
  frame_buffer->pixels = malloc(sizeof(int) * size);
  frame_buffer->width = width;
  frame_buffer->height = height;
  while (i++ < size)
    frame_buffer->pixels[i] = 0;
  return (frame_buffer);
}

void			display_window(t_map *my_map, t_player *player)
{
  sfTexture_updateFromPixels(TEXTURE, PIXELS, WIDTH, HEIGHT, 0, 0);
  sfRenderWindow_clear(my_map->window, sfBlack);
  sfRenderWindow_drawSprite(my_map->window, my_map->map, NULL);
  if (player->weapon == 0 && player->mode == 0)
    sfRenderWindow_drawSprite(my_map->window, player->gun, NULL);
  else if (player->weapon == 0 && player->mode == 1)
    sfRenderWindow_drawSprite(my_map->window, player->portal, NULL);
  else if (player->weapon == 2 && player->mode == 0)
    sfRenderWindow_drawSprite(my_map->window, player->knife, NULL);
  else if (player->weapon == 1 && player->mode == 0)
    sfRenderWindow_drawSprite(my_map->window, player->gun_fire, NULL);
  else if (player->weapon == 2 && player->mode == 1)
    sfRenderWindow_drawSprite(my_map->window, player->repare_tool, NULL);
  else if (player->weapon == 3 && player->mode == 1)
    sfRenderWindow_drawSprite(my_map->window, player->hammer, NULL);
  sfRenderWindow_display(my_map->window);
}

int			main(int ac, char **av)
{
  t_map			my_map;
  t_player		player;

  my_map.window = create_window("|| WOLF 3D ||", WIDTH, HEIGHT);
  my_map.map = sfSprite_create();
  my_map.texture_map = sfTexture_create(WIDTH, HEIGHT);
  sfSprite_setTexture(my_map.map, my_map.texture_map, sfTrue);
  my_map.buffer = my_framebuffer_create(WIDTH, HEIGHT);
  my_map.ac = ac;
  my_map.av = av;
  wolf3d(&my_map, &player, ac, av);
  display_menu(&my_map, &player);
  check_wall(&my_map, &player);
  display_window(&my_map, &player);
  while (sfRenderWindow_isOpen(my_map.window))
    check_key(&my_map, &player);
  if (player.mode == 1)
    edit_map(&my_map);
  destroy_all(&my_map, &player);
  close(my_map.fd);
  return (0);
}
