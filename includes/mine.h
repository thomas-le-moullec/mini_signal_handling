/*
** mine.h for mine in /home/le-mou_t/rendu/PSU_2015_minitalk
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 17:43:56 2016 Thomas LE MOULLEC
** Last update Wed Feb  3 14:47:20 2016 Thomas LE MOULLEC
*/

#ifndef MINE_H_
# define MINE_H_

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*my_lib*/
void		my_put_nbr(int);
int		my_get_nbr(char *);
void		my_putchar(char);
char		*my_strcat(char *, char *, int, int);
char            *put_nbr_str(char *, int, int, int);

/*my_assist*/
char		*my_strcar(char *, char);
int		my_strlen(char *);
void            my_putstr(char *);

/*client*/
int		check_entries(int, char **);
char		*glue_it(char *, int, char *);
void            put_bin(char, int);

/*client*/
int		serv_it();
void		sig_ok(int);
void		sig_no(int);

#endif
