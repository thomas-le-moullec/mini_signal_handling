/*
** serv_pid.c for serv_pid in /home/le-mou_t/rendu/PSU_2015_minitalk/serveur
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Feb  6 20:54:21 2016 Thomas LE MOULLEC
** Last update Mon Feb 15 15:34:24 2016 Thomas LE MOULLEC
*/

#include "mine.h"

int			check_in_tab(char **tab, int pid)
{
  int			y;

  y = 0;
  while (tab[y] != NULL)
    {
      if (str_cmp(char_nbr(pid), tab[y]) != -1)
	return (y);
      y++;
    }
  return (-1);
}

int			count_tab(char **tab)
{
  int			y;

  y = 0;
  while (tab[y] != NULL)
    y++;
  return (y);
}

char			**create_pid(char **tab, int pid)
{
  char			**stock;
  char			*cli;
  int			x;
  int			y;

  y = 0;
  if (pid < 1)
    return (tab);
  if ((stock = malloc(sizeof(char *) * count_tab(tab) + 2)) == NULL)
    return (NULL);
  while (tab[y] != NULL)
    {
      x = 0;
      if ((stock[y] = malloc(sizeof(char) * my_strlen(tab[y]) + 1)) == NULL)
	return (NULL);
      while (tab[y][x] != '\0')
	{
	  stock[y][x] = tab[y][x];
	  x++;
	}
      stock[y][x] = '\0';
      y++;
    }
  cli = char_nbr(pid);
  x = 0;
  if ((stock[y] = malloc(sizeof(char) * my_strlen(cli) + 1)) == NULL)
    return (NULL);
  while (cli[x] != '\0')
    {
      stock[y][x] = cli[x];
      x++;
    }
  stock[y++][x] = '\0';
  stock[y] = NULL;
  return (stock);
}

void			print_pid(int serv_pid)
{
  my_putstr("PID: ");
  my_put_nbr(serv_pid);
  my_putchar('\n');
}
