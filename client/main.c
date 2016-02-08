/*
** main.c for main in /home/le-mou_t/rendu/PSU_2015_minitalk/client
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 23:06:59 2016 Thomas LE MOULLEC
** Last update Mon Feb  8 13:06:30 2016 Thomas LE MOULLEC
*/

#include "mine.h"

int		g_bit = -1;

void		go_ping(int sig)
{
  if (sig == SIGUSR1)
    g_bit = 1;
  if (sig == SIGUSR2)
    g_bit = 0;
}

int		ping_pong(char c, int serv_pid)
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
      while (g_bit != 1)
	usleep(1);
      g_bit = -1;
    }
  return (0);
}

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
      usleep(1000);
    }
}

int		hand_it(char *stock, int serv_pid, char **av)
{
  int		i;

  i = 0;
  while (stock[i] != '\0')
    {
      put_bin(stock[i], serv_pid);
      i++;
    }
  i = 0;
  while (av[2][i] != '\0')
    {
      ping_pong(av[2][i], serv_pid);
      i++;
    }
  ping_pong('\0', serv_pid);
  return (0);
}

int		main(int ac, char **av)
{
  char		*stock;
  int		client_pid;
  int		serv_pid;

  signal(SIGUSR1, go_ping);
  signal(SIGUSR2, go_ping);
  if (check_entries(ac, av) == -1)
    return (-1);
  client_pid = getpid();
  serv_pid = my_get_nbr(av[1]);
  if ((stock = malloc(sizeof(char))) == NULL)
    return (-1);
  stock = glue_it(stock, client_pid);
  if ((hand_it(stock, serv_pid, av)) == -1)
    return (-1);
  if (stock != NULL)
    free(stock);
  printf("Processus from PID : %d -- Done\n", client_pid);
  return (0);
}
