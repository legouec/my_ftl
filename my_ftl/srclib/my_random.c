/*
** random.c for  in /home/naniev/ETNA/FDI-DEVC/Shifumi/legoue_c/shifumi
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Fri Oct 27 18:43:37 2017 LEGOUEST Clement
** Last update Thu Nov  9 13:42:10 2017 LEGOUEST Clement
*/

#include <stdlib.h>

int my_random(int nb)
{
  int	my_random;

  my_random = rand()%nb;

  return (my_random);
}
