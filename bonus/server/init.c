/*
** init.c for init in /home/le-mou_t/rendu/PSU_2015_minitalk/bonus
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Feb 13 17:00:19 2016 Thomas LE MOULLEC
** Last update Mon Feb 15 18:36:13 2016 Thomas LE MOULLEC
*/

#include "mine.h"

char		**init_tab(char **tab, int pid)
{
  char		*stock;
  int		x;

  x = 0;
  stock = char_nbr(pid);
  if ((tab = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  if ((tab[0] = malloc(sizeof(char) * my_strlen(stock) + 1)) == NULL)
    return (NULL);
  while (stock[x] != '\0')
    {
      tab[0][x] = stock[x];
      x++;
    }
  tab[0][x] = '\0';
  tab[1] = NULL;
  return (tab);
}

char		*char_nbr(int pid)
{
  char		*stock;
  int           x;
  int		i;

  i = 0;
  x = 1;
  if ((stock = malloc(sizeof(char) * 12)) == NULL)
    return (NULL);
  if (pid < 0)
    stock[i++] = '-';
  else
    pid = -pid;
  while (pid / x < -9)
    x = x * 10;
  while (x)
    {
      stock[i] = (-(pid / x)) + '0';
      pid = pid % x;
      i++;
      x = x / 10;
    }
  stock[i] = '\0';
  return (stock);
}

int             str_cmp(char *one, char *nd)
{
  int           i;

  i = 0;
  while (one[i] != '\0')
    {
      if (one[i] != nd[i])
        return (-1);
      i++;
    }
  if (one[i] != nd[i])
    return (-1);
  return (0);
}
