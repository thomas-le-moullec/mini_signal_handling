/*
** main.c for main in /home/le-mou_t/rendu/PSU_2015_minitalk/client
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 23:06:59 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 18:27:52 2016 Thomas LE MOULLEC
*/

#include "mine.h"

void		put_bin(char c, int serv_pid)
{
  int		i;

  i = 7;
  while (i >= 0)
    {
      if ((c & (1u << i)) == 0)
	kill(serv_pid, SIGUSR2);
      else
	kill(serv_pid, SIGUSR1);
      i--;
      usleep(800);
    }
}

int		main(int ac, char **av)
{
  char		*stock;
  int		client_pid;
  int		serv_pid;
  int		i;

  i = 0;
  if (check_entries(ac, av) == -1)
    return (-1);
  client_pid = getpid();
  serv_pid = my_get_nbr(av[1]);
  if ((stock = malloc(sizeof(char))) == NULL)
    return (-1);
  stock = glue_it(stock, client_pid, av[2]);
  while (stock[i] != '\0')
    {
      put_bin(stock[i], serv_pid);
      i++;
    }
  if (stock != NULL)
    free(stock);
  return (0);
}
