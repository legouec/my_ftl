/*
** my_swap.c for  in /home/naniev/ETNA/FDI-DEVC/Jour03/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Oct 18 18:01:08 2017 LEGOUEST Clement
** Last update Wed Oct 18 19:33:09 2017 LEGOUEST Clement
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *b;
  *b = *a;
  *a = c;
}
