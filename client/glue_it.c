/*
** glue_it.c for glue_it in /home/le-mou_t/rendu/PSU_2015_minitalk/client
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Wed Feb  3 10:38:32 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 10:38:55 2016 Thomas LE MOULLEC
*/

#include "mine.h"

char            *glue_it(char *stock, int pid, char *str)
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
  if (str != NULL || str[0] != '\0')
    stock = my_strcat(stock, str, 0, 0);
  return (stock);
}
