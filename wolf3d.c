/*
** wolf3d.c for  in /home/nico_lrnt/Documents/GCP/wolf3d
** 
** Made by nico_lrnt
** Login   <nicolas.laurent@epitech.eu>
** 
** Started on  Mon Dec 12 11:53:05 2016 nico_lrnt
** Last update Thu Jan 12 13:00:39 2017 nico_lrnt
*/

#include "include/structure.h"
#include "include/prototype.h"
#include "include/my.h"

void	display_help()
{
  my_printf("\n\n\tO---------------------------------------O\n");
  my_printf("\t|\tH O W   T O   P L A Y  :\t|\n\t|\t\t\t\t\t|\n");
  my_printf("\t|Press :\t\t\t\t|\n");
  my_printf("\t|\tZ | UP\t  -->\tMove Forward\t|\n");
  my_printf("\t|\tS | DOWN  -->\tMove Backward\t|\n");
  my_printf("\t|\tQ\t  -->\tMove Left\t|\n\t|\tD\t  -->\tMove Right\t|\n");
  my_printf("\t|\tLEFT\t  -->\tLook Left\t|\n");
  my_printf("\t|\tRIGHT\t  -->\tLook Right\t|\n");
  my_printf("\t|\tC\t  -->\tLook Up\t\t|\n\t|\tX\t  -->\tLook Center\t|\n");
  my_printf("\t|\tW\t  -->\tLook Down\t|\n\t|\tSPACE\t  -->\tJump\t\t|\n");
  my_printf("\t|\t\t\t\t\t|\n");
  my_printf("\t|\tO\t  -->\tSpeed Up\t|\n\t|\tL\t  -->\tSpeed Down\t|\n");
  my_printf("\t|\t\t\t\t\t|\n");
  my_printf("\t|\t1\t  -->\tTake Gun\t|\n\t|\t2\t  -->\tTake Knife\t|\n");
  my_printf("\t|\t3\t  -->\tTake Machine-Gun|\n");
  my_printf("\t|\t4\t  -->\tDrop Weapon\t|\n");
  my_printf("\t|\tE\t  -->\tShoot !\t\t|\n");
  my_printf("\t|\t\t\t\t\t|\n");
  my_printf("\t|\tM\t  -->\tPlay Music\t|\n");
  my_printf("\t|\t\t\t\t\t|\n");
  my_printf("\t|\tESCAPE\t  -->\tQuit Game\t|\n");
  my_printf("\t|\t\t\t\t\t|\n");
  my_printf("\tO---------------------------------------O\n\n\n");
  exit(0);
}

void	check_file(t_map *my_map, int ac, char **av)
{
  int	ret;

  if (ac != 2)
    exit(84);
  if (av[1][0] == '-' && av[1][1] == 'h')
    display_help();
  if ((my_map->fd = open(av[1], O_RDWR)) == -1)
    exit(84);
  (*my_map).file = malloc(sizeof(char) * 1001);
  ret = read(my_map->fd, (*my_map).file, 1000);
  (*my_map).file[ret] = '\0';
}

void	get_size(t_map *my_map)
{
  int	i;
  int	x;
  int	y;

  i = -1;
  x = 0;
  y = 0;
  while (my_map->file[++i] != '\n')
    x++;
  while (my_map->file[++i] != '\0')
    if (my_map->file[i] == '\n')
      y++;
  my_map->line = y + 1;
  my_map->colon = x;
}

void	get_coord(t_map *my_map)
{
  int	i;
  int	j;
  int	k;

  my_map->tab = malloc(sizeof(int*) * my_map->line + 10);
  i = 0;
  k = -1;
  while (++k < my_map->line)
    {
      my_map->tab[k] = malloc(sizeof(int) * my_map->colon + 10);
      j = -1;
      while (++j < my_map->colon)
	{
	  my_map->file[i] == '0' ? my_map->tab[k][j] = 0 : 0;
	  my_map->file[i] == '1' ? my_map->tab[k][j] = 1 : 0;
	  my_map->file[i] == '2' ? my_map->tab[k][j] = 2 : 0;
	  my_map->file[i] == '3' ? my_map->tab[k][j] = 3 : 0;
	  my_map->file[i] == '4' ? my_map->tab[k][j] = 4 : 0;
	  my_map->file[i] == '5' ? my_map->tab[k][j] = 5 : 0;
	  my_map->file[i] == '6' ? my_map->tab[k][j] = 6 : 0;
	  my_map->file[i] == '7' ? my_map->tab[k][j] = 7 : 0;
	  i++;
	}
      i++;
    }
}

void	wolf3d(t_map *my_map, t_player *player, int ac, char **av)
{
  check_file(my_map, ac, av);
  get_size(my_map);
  get_coord(my_map);
  find_perso(my_map, player);
  define_the_plan(my_map);
  create_weapon(player);
  sfRenderWindow_setFramerateLimit(my_map->window, 60);
  player->angle = 0;
  player->speed = 100;
  player->weapon = 4;
  player->portal_4 = 0;
  player->portal_7 = 0;
  my_map->center = 0;
}
