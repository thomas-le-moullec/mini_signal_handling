/*
** main.c for main in /home/le-mou_t/rendu/PSU_2015_minitalk/client
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 23:06:59 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 00:16:03 2016 Thomas LE MOULLEC
*/

#include "mine.h"

int		check_entries(int ac, char **av)
{
  int		cmpt;

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

char		*glue_it(char *stock, int pid, char *str)
{
  int		x;

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

int		main(int ac, char **av)
{
  char		*stock;
  int		client_pid;

  if (check_entries(ac, av) == -1)
    return (-1);
  client_pid = getpid();
  if ((stock = malloc(sizeof(char))) == NULL)
    return (-1);
  stock = glue_it(stock, client_pid, av[2]);
  my_putstr(stock);
  if (stock != NULL)
    free(stock);
  return (0);
}
