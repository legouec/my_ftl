/*
** my_strlen.c for  in /home/naniev/ETNA/FDI-DEVC/Jour03
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Oct 18 09:25:18 2017 LEGOUEST Clement
** Last update Tue Oct 24 14:33:49 2017 LEGOUEST Clement
*/

int	my_strlen (char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
