/*
** my_putstr.c for  in /home/naniev/ETNA/FDI-DEVC/Jour03/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Oct 18 11:19:05 2017 LEGOUEST Clement
** Last update Tue Oct 24 14:30:33 2017 LEGOUEST Clement
*/

void	my_putchar (char c);

void	my_putstr (char *str)
{
  while (*str != '\0')
    my_putchar (*str++);
}
