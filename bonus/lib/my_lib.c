/*
** my_lib.c for my_lib in /home/le-mou_t/rendu/PSU_2015_minitalk/lib
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 22:57:16 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 00:19:58 2016 Thomas LE MOULLEC
*/

#include "mine.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

char             *put_nbr_str(char *str, int nbr, int i, int nb)
{
  int           x;

  x = 1;
  if (str != NULL)
    {
      free(str);
      str = NULL;
    }
  if ((str = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  if (nbr < 0)
    str[i++] = '-';
  else
    nbr = -nbr;
  while (nbr / x < -9)
    x = x * 10;
  while (x)
    {
      str[i] = (-(nbr / x)) + '0';
      nbr = nbr % x;
      i++;
      x = x / 10;
    }
  str[i] = '\0';
  return (str);
}

int     my_get_nbr(char *str)
{
  int   i;
  int   c;
  int   nb;

  nb = 0;
  c = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-'))
        return (0);
      while (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
          c++;
      while (str[i] >= '0' && str[i] <= '9')
        {
          nb = (nb + str[i] - '0') * 10;
          i++;
        }
    }
  if (c % 2 == 1)
    nb = -nb;
  return (nb / 10);
}

void     my_put_nbr(int nb)
{
  int   x;

  x = 1;
  if (nb < 0)
    my_putchar('-');
  else
    nb = -nb;
  while (nb / x < -9)
    x = x * 10;
  while (x)
    {
      my_putchar(-(nb / x) + '0');
      nb = nb % x;
      x = x / 10;
    }
}

char    *my_strcat(char *dest, char *src, int i, int a)
{
  char  *result;

  if ((result = malloc(sizeof(char *) * (my_strlen(dest) + \
                                        my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      result[i] = dest[i];
      i++;
    }
  while (src[a] != '\0')
    {
      result[i] = src[a];
      i++;
      a++;
    }
  result[i] = '\0';
  if (dest != NULL)
    {
      free(dest);
      dest = NULL;
    }
  return (result);
}
