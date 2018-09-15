/*
** 
** Made by Thomas LE MOULLEC
** 
** Started on  Tue Feb  2 23:02:44 2016 Thomas LE MOULLEC
** Last update Sat Feb  6 15:31:48 2016 Thomas LE MOULLEC
*/

#include "mine.h"

char    *my_strcar(char *str, char c)
{
  int   i;
  char  *stock;

  i = 0;
  while (str[i] != '\0')
    i++;
  if ((stock = malloc(sizeof(char) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      stock[i] = str[i];
      i++;
    }
  free(str);
  stock[i] = c;
  i++;
  stock[i] = '\0';
  return (stock);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
