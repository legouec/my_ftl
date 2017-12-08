/*
** my_strcpy.c for  in /home/naniev/ETNA/FDI-DEVC/Jour04/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Thu Oct 19 14:40:52 2017 LEGOUEST Clement
** Last update Tue Oct 24 15:21:10 2017 LEGOUEST Clement
*/

char	*my_strcpy(char *dest, char *src)
{
  while (*src)
    {
      *dest = *src;
      dest++;
      src++;
    }
  return (dest);
}
