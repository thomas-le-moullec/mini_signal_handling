/*
** main.c for main in /home/le-mou_t/rendu/PSU_2015_minitalk/server
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 23:06:24 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 18:19:21 2016 Thomas LE MOULLEC
*/

#include "mine.h"

char		lolo = 0;

void		sig_ok(int sig)
{
  if (sig == SIGUSR1)
    lolo = lolo | 1;
}

int			serv_it()
{
  int			cmpt;

  cmpt = 1;
  while (cmpt)
    {
      pause();
      if (cmpt % 8 == 0)
	{
	  my_putchar(lolo);
	  lolo = 0;
	}
      lolo = lolo << 1;
      cmpt++;
    }
  return (0);
}

void		print_pid()
{
  int		serv_pid;

  serv_pid = getpid();
  my_putstr("PID: ");
  my_put_nbr(serv_pid);
  my_putchar('\n');
}

int		main()
{
  print_pid();
  signal(SIGUSR2, sig_ok);
  signal(SIGUSR1, sig_ok);
  serv_it();
  return (0);
}
