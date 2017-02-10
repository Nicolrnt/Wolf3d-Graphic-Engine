##
## Makefile for  in /home/nico_lrnt/bonus
## 
## Made by Nico_lrnt
## Login   <nico_lrnt@epitech.net>
## 
## Started on  Sat Oct 29 18:20:46 2016 Nico_lrnt
## Last update Sat Jan 14 21:27:35 2017 nico_lrnt
##

SRC	= main.c		\
	  menu.c		\
	  wolf3d.c		\
	  my_mini_map.c		\
	  draw_map.c		\
	  moves.c		\
	  other_key.c		\
	  raycasting.c		\
	  create_weapon.c	\
	  check_teleport.c	\
	  enemy.c		\
	  src/my_put_pixel.c	\
	  src/my_draw_line.c	\
	  src/move_forward.c	\
	  src/raycast.c

INC	= -I include

FLAG	= -W -Wall -Werror -Wextra

NAME	= wolf3d

MATH	= -lm

CSFML	= -l csfml-graphics -l csfml-window -l csfml-audio

MY_LIB	= -L./lib/my -lmy

all:	$(NAME)

$(NAME):
	gcc -g3 $(FLAG) -o $(NAME) $(SRC) $(MY_LIB) $(CSFML) $(MATH) $(INC)

clean:
	rm -f $(NAME)

fclean: clean
	find \( -name \*\~ -o -name \#\*\# \) -delete

re:	fclean all
