/*
** my_strcmp.c for  in /home/naniev/ETNA/FDI-DEVC/Jour04/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Thu Oct 19 19:04:02 2017 LEGOUEST Clement
** Last update Tue Oct 24 18:11:54 2017 LEGOUEST Clement
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  
  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0') && (i < (n)))
    {
      i++;
    }
  i = s1[i] - s2[i];
  if (i == 0)
    {
      return (0);
    }
  else if (i < 0)
    {
      return (-1);
    }
  else if (i > 0)
    {
      return (1);
    }
  return (0);
}
