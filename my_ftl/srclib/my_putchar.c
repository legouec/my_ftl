/*
** my_char.c for  in /home/naniev/ETNA/FDI-DEVC/Jour01/legoue_c/my_char
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Mon Oct 16 19:36:14 2017 LEGOUEST Clement
** Last update Tue Oct 24 17:47:41 2017 LEGOUEST Clement
*/

#include<unistd.h>

void	my_putchar (char c)
{
  write (1,&c,1);
}
