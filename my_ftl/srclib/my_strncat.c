/*
** my_strcat.c for  in /home/naniev/ETNA/FDI-DEVC/libmy_01
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Tue Oct 24 15:32:48 2017 LEGOUEST Clement
** Last update Tue Oct 24 17:50:02 2017 LEGOUEST Clement
*/

char	*my_strncat (char *dest, char *src, int n)
{
  int	idx;
  int	idx2;

  idx = 0;
  idx2 = 0;
  while (dest[idx2] != '\0')
      idx2 ++;
  while ((src[idx] != '\0') && (idx <= n))
      dest[idx2++] = src[idx++];
  idx2 ++;
  dest[idx2] = '\0';
  return (0);
}
