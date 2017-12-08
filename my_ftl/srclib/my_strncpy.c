/*
** my_strcpy.c for  in /home/naniev/ETNA/FDI-DEVC/Jour04/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Thu Oct 19 14:40:52 2017 LEGOUEST Clement
** Last update Tue Oct 24 15:22:20 2017 LEGOUEST Clement
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while ((i <= n-1) || (src[i] <= '\0'))
    {
      *dest = *src;
      dest++;
      src++;
      i++;
    }
  return (dest);
}
