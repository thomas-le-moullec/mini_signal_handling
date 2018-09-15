/*
** 
** Made by Thomas LE MOULLEC
** 
** Started on  Wed Feb  3 10:39:58 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 10:40:27 2016 Thomas LE MOULLEC
*/

#include "mine.h"

int             check_entries(int ac, char **av)
{
  int           cmpt;

  cmpt = 0;
  if (ac != 3)
    return (-1);
  while (av[1][cmpt] != '\0')
    {
      if (av[1][cmpt] < '0' || av[1][cmpt] > '9')
        return (-1);
      cmpt++;
    }
  return (0);
}
