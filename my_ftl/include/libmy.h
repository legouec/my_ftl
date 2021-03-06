/*
** libmy.h for  in /home/naniev/ETNA/FDI-DEVC/libmy_01/legoue_c/libmy_01
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Fri Oct 27 10:24:20 2017 LEGOUEST Clement
** Last update Wed Nov  8 14:00:23 2017 LEGOUEST Clement
*/

#ifndef _LIBMY_H_
#define _LIBMY_H_

int     my_getnbr(char *str);
int     my_isneg(int n);
void    my_putchar(char c);
void    my_put_nbr(int nb);
int	my_random();
char    *my_strcat(char *str1, char *str2);
char    *my_strcpy(char *dest, char *src);
char    *my_strncat(char *str1, char *str2, int n);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char *src, int n);
char    *my_strstr(char *str, char *to_find);
void    my_swap(int *a, int *b);
char	*readline();

#endif /* !_LIBMY_H_*/
