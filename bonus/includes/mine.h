/*
** mine.h for mine in /home/le-mou_t/rendu/PSU_2015_minitalk
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Tue Feb  2 17:43:56 2016 Thomas LE MOULLEC
** Last update Mon Feb 15 15:30:23 2016 Thomas LE MOULLEC
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
int             ping_pong(char, int);
void            go_ping(int);

/*serveur*/
int             pong_it(int);
void            print_pid(int);
int		calc_in(int);
void            handler_signal(int, siginfo_t *, void *);
int		sig_it(char **);
int             check_in_tab(char **, int);

/*init*/
char		**init_tab(char **, int);
char            *char_nbr(int);
int             str_cmp(char *, char *);
char            **create_pid(char **, int);

#endif
