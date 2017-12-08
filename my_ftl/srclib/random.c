/*
** random.c for  in /home/naniev/ETNA/FDI-DEVC/Shifumi/legoue_c/shifumi
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Fri Oct 27 18:43:37 2017 LEGOUEST Clement
** Last update Sat Oct 28 02:12:42 2017 LEGOUEST Clement
*/

#include <stdlib.h>
#include <time.h>

int random()
{
  int	random;

  srand (time (NULL));
  random = rand() % 5 + 1;

  return (random);
}
