/*
** prototype.h for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Mon Dec 12 11:55:51 2016 nico_lrnt
** Last update Sat Jan 14 21:39:30 2017 nico_lrnt
*/

#ifndef	PROTOTYPE_H_
# define PROTOTYPE_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH	(1920 / 1)
# define HEIGHT	1080

# define MAP_X	x + (j * (*my_map).size_line)
# define MAP_Y	y + (k * (*my_map).size_colon) + 50

# define FOV	60
# define DEG	M_PI / 180
# define PLAN	plan[plan.angle][plan.i]

# define POS	my_map->tab[player->y / WIDTH + 1][player->x / WIDTH + 1]
# define WALL	my_map->tab[wall.y / WIDTH + 1][wall.x / WIDTH + 1]
# define WALL4	WALL == 4 ? 4
# define WALL7	WALL == 7 ? 7
# define MOVE	my_map->tab[y / WIDTH + 1][x / WIDTH + 1]
# define BULLET	my_map->tab[bullet.y / WIDTH + 1][bullet.x / WIDTH + 1]

# define SLIDE_V	my_map->tab[y / WIDTH + 1][player->x / WIDTH + 1]
# define SLIDE_H	my_map->tab[player->y / WIDTH + 1][x / WIDTH + 1]

# define TEXTURE	my_map->texture_map
# define PIXELS		my_map->buffer->pixels
# define COEF		(my_map->last_len - len)
# define MY_COEF	my_map->coef

# define GUN	player->weapon == 0
# define KNIFE	(player->weapon == 2 && len < 1.25)
# define REPARE	player->weapon == 2

# define MENU	my_map->menu_state
# define MENU_1	"include/img/menu_1.png"
# define MENU_2	"include/img/menu_2.png"
# define MENU_3	"include/img/menu_3.png"

# define MUSIC_1	"include/sound/construct.ogg"
# define WEAPON_1	"include/img/knife.png"
# define WEAPON_2	"include/img/portal.png"
# define WEAPON_3	"include/img/hammer.png"
# define WEAPON_4	"include/img/gun_fire.png"
# define WEAPON_5	"include/img/repare_tool.png"
# define TEXTURE_1	player->texture_repare_tool

# define SIZE_LINE	my_map->size_line

# define KEY(my_key)	sfKeyboard_isKeyPressed(my_key)

typedef struct s_my_framebuffer t_my_framebuffer;
typedef struct s_map t_map;
typedef struct s_player t_player;

/* draw_map.c */
void	edit_map(t_map *my_map);
void	gray_it(sfColor *color, int key);
void	my_draw_wall(t_map *my_map, int x, float len, int key);
void	draw_map(t_map *my_map);

/* check_wall.c */
void	check_wall(t_map *my_map, t_player *player);
void	malloc_the_plan(t_map *my_map);
void	define_the_plan(t_map *my_map);

/* check_teleport.c */
void	check_teleport(t_map *my_map, t_player *player);

/* enemy.c */
void	check_enemy(t_map *my_map, t_player *player);

/* my_mini_map.c */
void	put_perso(t_map *my_map, t_player *player);
void	find_perso(t_map *my_map, t_player *player);
void	my_mini_map(t_map *my_map, t_player *player);

/* wolf3d.c */
void	wolf3d(t_map *my_map, t_player *player, int ac, char **av);

/* moves.c */
void	check_key_up(t_map *my_map, t_player *player);
void	check_key_left(t_map *my_map, t_player *player);
void	check_key_right(t_map *my_map, t_player *player);
void	check_key_down(t_map *my_map, t_player *player);
void	check_key(t_map *my_map, t_player *player);

/* other_key.c */
void	change_center(t_map *my_map, t_player *player, int key);
void	check_key_move(t_map *my_map, t_player *player, int key);
void	change_weapon(t_map *my_map, t_player *player, int key);
void	shoot(t_map *my_map, t_player *player);
void	play_music();

/* create_weapon.c */
void	create_weapon(t_player *player);

/* menu.c */
void	display_menu(t_map *my_map, t_player *player);

/* main.c */
void	distroy_all(t_map *my_map, t_player *player);
void	display_window(t_map *my_map, t_player *player);

/* src */
void	my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color);

void	my_draw_line(t_my_framebuffer *buffer, sfVector2i from,
		     sfVector2i to, sfColor color);

sfVector2f	move_forward(sfVector2f pos, float direction, float distance);

#endif /* !PROTOTYPE_H_ */
