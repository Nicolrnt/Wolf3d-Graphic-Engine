/*
** create_weapon.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Wed Jan  4 19:00:45 2017 nico_lrnt
** Last update Sat Jan 14 21:38:37 2017 nico_lrnt
*/

#include "structure.h"
#include "prototype.h"
#include "my.h"

void		create_music(t_player *player)
{
  player->music_gun = sfMusic_createFromFile("include/sound/basic_shoot.ogg");
  player->music_knife = sfMusic_createFromFile("include/sound/stab.ogg");
  player->music_repare_tool = sfMusic_createFromFile(MUSIC_1);
  player->music_hammer = sfMusic_createFromFile("include/sound/destroy.ogg");
  player->music_portal = sfMusic_createFromFile("include/sound/portal.ogg");
  player->music_game = sfMusic_createFromFile("include/sound/wolf_music.ogg");
}

void		create_weapon_3(t_player *player)
{
  sfVector2f	position;
  sfVector2f	scale;

  player->knife = sfSprite_create();
  player->portal = sfSprite_create();
  player->texture_knife = sfTexture_createFromFile(WEAPON_1, NULL);
  player->texture_portal = sfTexture_createFromFile(WEAPON_2, NULL);
  sfSprite_setTexture(player->knife, player->texture_knife, sfTrue);
  sfSprite_setTexture(player->portal, player->texture_portal, sfTrue);
  position.x = (WIDTH / 2) - (1016 / 2);
  position.y = (HEIGHT - 648);
  scale.x = 1;
  scale.y = 1;
  sfSprite_setPosition(player->knife, position);
  sfSprite_setScale(player->knife, scale);
  position.x = WIDTH - 1086;
  position.y = HEIGHT - 727;
  scale.x = 1;
  scale.y = 1;
  sfSprite_setPosition(player->portal, position);
  sfSprite_setScale(player->portal, scale);
  create_music(player);
}

void		create_weapon_2(t_player *player)
{
  sfVector2f	position;
  sfVector2f	scale;

  player->hammer = sfSprite_create();
  player->gun_fire = sfSprite_create();
  player->texture_hammer = sfTexture_createFromFile(WEAPON_3, NULL);
  player->texture_gun_fire = sfTexture_createFromFile(WEAPON_4, NULL);
  sfSprite_setTexture(player->hammer, player->texture_hammer, sfTrue);
  sfSprite_setTexture(player->gun_fire, player->texture_gun_fire, sfTrue);
  position.x = 800;
  position.y = 750;
  scale.x = 1.5;
  scale.y = 1.5;
  sfSprite_setPosition(player->hammer, position);
  sfSprite_setScale(player->hammer, scale);
  position.x = (WIDTH / 2) - ((996 * 0.75) / 2);
  position.y = HEIGHT - (797 * 0.75);
  scale.x = 0.75;
  scale.y = 0.75;
  sfSprite_setPosition(player->gun_fire, position);
  sfSprite_setScale(player->gun_fire, scale);
  create_weapon_3(player);
}

void		create_weapon(t_player *player)
{
  sfVector2f    position;
  sfVector2f    scale;

  player->gun = sfSprite_create();
  player->repare_tool = sfSprite_create();
  player->texture_gun = sfTexture_createFromFile("include/img/gun.png", NULL);
  player->texture_repare_tool = sfTexture_createFromFile(WEAPON_5, NULL);
  sfSprite_setTexture(player->gun, player->texture_gun, sfTrue);
  sfSprite_setTexture(player->repare_tool, TEXTURE_1, sfTrue);
  position.x = (WIDTH / 2) - ((998 * 0.75) / 2);
  position.y = HEIGHT - (800 * 0.75);
  scale.x = 0.75;
  scale.y = 0.75;
  sfSprite_setPosition(player->gun, position);
  sfSprite_setScale(player->gun, scale);
  position.x = 700;
  position.y = 500;
  scale.x = 1.5;
  scale.y = 1.5;
  sfSprite_setPosition(player->repare_tool, position);
  sfSprite_setScale(player->repare_tool, scale);
  create_weapon_2(player);
}
