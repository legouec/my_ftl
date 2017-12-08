/*
** my_strstr.c for  in /home/naniev/ETNA/FDI-DEVC/libmy_01
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Tue Oct 24 16:28:01 2017 LEGOUEST Clement
** Last update Tue Oct 24 17:59:51 2017 LEGOUEST Clement
*/

char *my_strstr (char *str, char *to_find)
{
  int idx;

  idx = 0;
  while (str[idx] != 0)
    {
      if (to_find[0] == str[idx])
	{
	  return (&str[idx]);
	}
      idx ++;
    }
  return ('\0');
}
