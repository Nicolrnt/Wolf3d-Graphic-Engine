/*
** structure.h for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Mon Dec 12 11:57:11 2016 nico_lrnt
** Last update Mon Feb  6 12:18:42 2017 nico_lrnt
*/

#ifndef STRUCTURE_H_
# define STRUCTURE_H_

# include "prototype.h"

typedef struct	s_wall
{
  float		len;
  int		x;
  int		y;
  int		i;
}		t_wall;

typedef struct	s_plan
{
  int		angle;
  int		ray;
  float		x;
  float		y;
  int		i;
}		t_plan;

typedef struct	s_player
{
  sfSprite	*gun;
  sfSprite	*gun_fire;
  sfSprite	*knife;
  sfSprite	*repare_tool;
  sfSprite	*hammer;
  sfSprite	*portal;
  sfTexture	*texture_gun;
  sfTexture	*texture_gun_fire;
  sfTexture	*texture_knife;
  sfTexture	*texture_repare_tool;
  sfTexture	*texture_hammer;
  sfTexture	*texture_portal;
  sfMusic	*music_gun;
  sfMusic	*music_knife;
  sfMusic	*music_repare_tool;
  sfMusic	*music_hammer;
  sfMusic	*music_portal;
  sfMusic	*music_game;
  int		x;
  int		y;
  int		angle;
  int		speed;
  int		weapon;
  int		mode;
  int		portal_4;
  int		portal_7;
}		t_player;

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct		s_map
{
  sfRenderWindow	*window;
  sfSprite		*map;
  sfSprite		*menu_1;
  sfSprite		*menu_2;
  sfSprite		*menu_3;
  sfSprite		*sky;
  sfTexture		*texture_map;
  sfTexture		*texture_menu_1;
  sfTexture		*texture_menu_2;
  sfTexture		*texture_menu_3;
  sfTexture		*texture_sky;
  sfVector2i   		**plan;
  t_my_framebuffer	*buffer;
  char			*file;
  int			**tab;
  char			**av;
  int			ac;
  int			fd;
  int			menu_state;
  int			size_line;
  int			line;
  int			size_colon;
  int			colon;
  int			perso_x;
  int			perso_y;
  int			center;
  int			i;
}			t_map;

#endif /* !STRUCTURE_H_ */
