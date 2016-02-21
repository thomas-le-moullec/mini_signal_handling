/*
** mine.h for mine in /home/le-mou_t/rendu/PSU_2015_minitalk
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 17:43:56 2016 Thomas LE MOULLEC
** Last update Sun Feb 21 19:58:22 2016 Thomas LE MOULLEC
*/

#ifndef MINE_H_
# define MINE_H_

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void		my_put_nbr(int);
int		my_get_nbr(char *);
void		my_putchar(char);
char		*my_strcat(char *, char *, int, int);
char            *put_nbr_str(char *, int, int, int);

char		*my_strcar(char *, char);
int		my_strlen(char *);
void            my_putstr(char *);

int		check_entries(int, char **);
char		*glue_it(char *, int);
void            put_bin(char, int);
int             ping_pong(char, int);
void            go_ping(int);
int             hand_it(char *, int, char **);

char		*serv_it(char *);
void		sig_ok(int);
int             pong_it(char *);
void            print_pid();
int		calc_in(int);
int             calc_pid();
char            *get_other_pid(char *);

#endif
