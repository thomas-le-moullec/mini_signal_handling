/*
** serv_pid.c for serv_pid in /home/le-mou_t/rendu/PSU_2015_minitalk/serveur
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Feb  6 20:54:21 2016 Thomas LE MOULLEC
** Last update Fri Feb 19 09:35:51 2016 Thomas LE MOULLEC
*/

#include "mine.h"

char		*get_other_pid(char *stock)
{
  if (stock != NULL && *(stock) != '\0')
    {
      free(stock);
      stock = NULL;
    }
  stock = NULL;
  if ((stock = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  *(stock) = '\0';
  return (stock);
}

void            print_pid()
{
  int           serv_pid;

  serv_pid = getpid();
  my_put_nbr(serv_pid);
  my_putchar('\n');
}

int             main()
{
  char          *stock;

  print_pid();
  stock = NULL;
  if ((stock = malloc(sizeof(char) * 1)) == NULL)
    return (-1);
  *(stock) = '\0';
  stock = serv_it(stock);
  pong_it(stock);
  if (stock != NULL)
    {
      free(stock);
      stock = NULL;
    }
  return (0);
}
