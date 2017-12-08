/*
** my_put_nbr.c for  in /home/naniev/ETNA/FDI-DEVC/Jour05-06/legoue_c/my_put_nbr
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Fri Oct 20 09:34:16 2017 LEGOUEST Clement
** Last update Tue Oct 24 14:17:41 2017 LEGOUEST Clement
*/

void	my_putchar(char c);

void	my_rec(int n)
{
  if (n > 0)
    {
      my_rec(n/10);
      my_putchar((n%10) + 48);
    }
}

void	my_put_nbr(int n)
{
  if (n == 0)
    {
      my_putchar (0 + 48);
    }
  else if (n < 0)
    {
      my_putchar ('-');
      n = n * (-1);
      my_rec (n);
    }
  else
    {
      my_rec(n);
    }
}
