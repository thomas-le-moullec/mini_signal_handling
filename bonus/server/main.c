/*
** main.c for main in /home/le-mou_t/rendu/PSU_2015_minitalk/server
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 23:06:24 2016 Thomas LE MOULLEC
** Last update Mon Feb 15 18:42:11 2016 Thomas LE MOULLEC
*/

#include "mine.h"

int		g_s_bit = 2;
int		glob_pid = -2;

void			handler_signal(int sig, siginfo_t *info, void *tp)
{
  if (sig == SIGUSR1)
    g_s_bit = 1;
  if (sig == SIGUSR2)
    g_s_bit = 0;
  glob_pid = info->si_pid;
  (void)tp;
}

int			calc_in(int client_pid)
{
  static int		i = 0;
  static char		res = 0;

  if (i == 0)
    res = 0;
  if (g_s_bit == 1)
    res = res | 1;
  if (i != 7)
    res = res << 1;
  i++;
  g_s_bit = 2;
  while ((kill(client_pid, SIGUSR1)) == -1);
  if (i > 7)
    {
      i = 0;
      if ((int)res == -1)
	return (0);
      return ((int)res);
    }
  return (-1);
}

int			pong_it(int client_pid)
{
  int			ret;

  ret = -1;
  while (g_s_bit == 2)
    printf("g_s_bit = %d\n", g_s_bit);
  ret = calc_in(client_pid);
  if (ret != 0 && ret != -1)
    {
      my_putchar(ret);
      ret = 0;
    }
  return (0);
}

int			sig_it(char **tab)
{
  int			client_pid;
  int			y;

  client_pid = glob_pid;
  if (client_pid > 0)
    {
      if ((y = check_in_tab(tab, client_pid)) == -1)
	tab = create_pid(tab, client_pid);
      else
	client_pid = my_get_nbr(tab[y]);
    }
  if (client_pid > 0 && g_s_bit != 2)
    pong_it(glob_pid);
  return (glob_pid);
}

int                     main()
{
  int                   serv_pid;
  struct sigaction      act;
  char			**tab;

  tab = NULL;
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = &handler_signal;
  sigemptyset(&act.sa_mask);
  serv_pid = getpid();
  print_pid(serv_pid);
  if ((sigaction(SIGUSR1, &act, NULL)) == -1)
    {
      write(2, "Sigaction failed\n", my_strlen("Sigaction failed\n"));
      return (-1);
    }
  if ((sigaction(SIGUSR2, &act, NULL)) == -1)
    {
      write(2, "Sigaction failed\n", my_strlen("Sigaction failed\n"));
      return (-1);
    }
  if ((tab = init_tab(tab, glob_pid)) == NULL)
    return (-1);
  while (sig_it(tab) != -1);
  printf("The end\n");
  return (-1);
}
