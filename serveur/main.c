/*
** main.c for main in /home/le-mou_t/rendu/PSU_2015_minitalk/server
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 23:06:24 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 00:00:46 2016 Thomas LE MOULLEC
*/

#include "mine.h"

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
  return (0);
}
