/*
** main.c for main in /home/le-mou_t/rendu/PSU_2015_minitalk/server
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 23:06:24 2016 Thomas LE MOULLEC
** Last update Mon Feb  8 13:25:18 2016 Thomas LE MOULLEC
*/

#include "mine.h"

int		g_s_bit = 2;

void		sig_ok(int sig)
{
  if (sig == SIGUSR1)
    g_s_bit = 1;
  if (sig == SIGUSR2)
    g_s_bit = 0;
}

int			calc_in(int client_pid)
{
  static int		i = 0;
  static char		res = 0;

  client_pid = client_pid;
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

int			pong_it(char *stock)
{
  int			ret;
  int			client_pid;

  ret = -1;
  client_pid = my_get_nbr(stock);
  while (42)
    {
      signal(SIGUSR2, sig_ok);
      signal(SIGUSR1, sig_ok);
      while (g_s_bit == 2);
      ret = calc_in(client_pid);
      if (ret == 0)
	{
          client_pid = my_get_nbr(serv_it(get_other_pid(stock)));
	  if (client_pid <= 0)
	    exit(write(2, "Error Pid\n", 10));
	}
      if (ret != 0 && ret != -1)
	{
	  my_putchar(ret);
	  ret = 0;
	}
    }
  return (0);
}

int                     calc_pid()
{
  static int            i = 0;
  static char           res = 0;

  if (i == 0)
    res = 0;
  if (g_s_bit == 1)
    res = res | 1;
  if (i != 7)
    res = res << 1;
  i++;
  g_s_bit = 2;
  if (i > 7)
    {
      i = 0;
      g_s_bit = 2;
      return ((int)res);
    }
  return (-1);
}

char                    *serv_it(char *stock)
{
  int                   ret;

  ret = -1;
  while (42)
    {
      signal(SIGUSR2, sig_ok);
      signal(SIGUSR1, sig_ok);
      while (g_s_bit == 2);
      ret = calc_pid();
      if (ret != -1)
        {
          if (ret == 58)
	    return (stock);
          stock = my_strcar(stock, ret);
          ret = -1;
        }
    }
  return (NULL);
}
