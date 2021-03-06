/*
** 
** Made by Thomas LE MOULLEC
** 
** Started on  Sat Feb  6 20:54:21 2016 Thomas LE MOULLEC
** Last update Fri Feb 19 10:58:39 2016 Thomas LE MOULLEC
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
  usleep(5);
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
