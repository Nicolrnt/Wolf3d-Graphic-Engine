/*
** my.h for  in /home/Nico_lrnt/CPool/CPool_Day10/lib/my
** 
** Made by Nicolas Laurent
** Login   <Nico_lrnt@epitech.net>
** 
** Started on  Mon Oct 17 12:48:40 2016 Nicolas Laurent
** Last update Fri Nov 25 21:42:22 2016 Nico_lrnt
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

# define SPE_1	(str[i] == ' ' || str[i] == '-' || str[i] == '+')
# define SPE_2	(str[i] == '#')

int	my_getnbr(char *str);
int	my_isneg(int n);
void	my_putchar(char c);
int	my_put_nbr(long int nb);
int	my_putstr(char *str);
char	*my_revstr(char *str);
char	*my_strcapitalize(char *str);
char	*my_strcpy(char *dest, char *src);
int	my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strisalpha(char *str);
char	*my_strncat(char *dest, char *src, int n);
int	my_strcmp(char *s1, char *s2);
int	my_str_isnum(char *str);
int	my_strncmp(char *s1, char *s2, int n);
int	my_power_rec(int nb, int p);
void	my_printf(char *format, ...);
void	my_put_nbr_double(double nb);
void	my_putnbr_base(int nbr, char *base);
void	my_put_octal(char *str);
void	my_putnbr_undec(unsigned int nb);
void	my_putnbr_unoct(unsigned int nb);
void	my_putnbr_unlowhex(unsigned int nb);
void	my_putnbr_unuphex(unsigned int nb);
void	my_put_address(long int a);
void	print_char(va_list args);
void	print_str(va_list args);
void	print_octal(va_list args);
void	print_nbr(va_list args);
void	print_undec(va_list args);
void	print_unoct(va_list args);
void	print_unlowhex(va_list args);
void	print_unuphex(va_list args);
void	print_address(va_list args);
void	print_bin(va_list args);
void	my_putnbr_base_add(long int nbr, char *base);

#endif	/* !MY_H_ */
