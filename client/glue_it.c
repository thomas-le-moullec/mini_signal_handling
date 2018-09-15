/*
** 
** Made by Thomas LE MOULLEC
** 
** Started on  Wed Feb  3 10:38:32 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 20:44:57 2016 Thomas LE MOULLEC
*/

#include "mine.h"

char            *glue_it(char *stock, int pid)
{
  int           x;

  x = 1;
  if (pid >= 0)
    while ((-pid / x ) < -9)
      x *= 10;
  else
    while (pid / x < -9)
      x *= 10;
  stock = put_nbr_str(stock, pid, 0, x);
  stock = my_strcar(stock, ':');
  return (stock);
}
