/*
** my_getnbr.c for  in /home/naniev/ETNA/FDI-DEVC/Jour05-06/legoue_c/my_getnbr
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Fri Oct 20 16:48:19 2017 LEGOUEST Clement
** Last update Fri Oct 27 15:34:00 2017 LEGOUEST Clement
*/

int	isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int		idx;
  long int	h;
  int		m;

  idx = 0;
  h = 0;
  m = 1;
  while (str[idx] == 43 || str[idx] == 45)
    {
      if (str[idx] == 45)
	m = -m;
      idx++;
    }
  while (isnum(str[idx]) == 1 && str[idx] != '\0')
    {
      h *= 10;
      h += str[idx] - 48;
      idx ++;
    }
  h = h * m;
  return (h);
}
