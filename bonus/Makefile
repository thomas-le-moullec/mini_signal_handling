##
## Makefile for Makefile in /home/le-mou_t/rendu/PSU_2015_minitalk
## 
## Made by Thomas LE MOULLEC
## Login   <le-mou_t@epitech.net>
## 
## Started on  Tue Feb  2 17:10:20 2016 Thomas LE MOULLEC
## Last update Sat Feb 13 18:48:40 2016 Thomas LE MOULLEC
##

NAME    =       ./server/server

NAME2   =       ./client/client

PATH1   =       ./server/

PATH2   =       ./client/

PATH3  	=       ./lib/

SRCS    =       $(PATH3)my_lib.c  	\
		$(PATH3)my_assist.c	\
		$(PATH1)main.c    	\
		$(PATH1)serv_pid.c	\
		$(PATH1)init.c		\

SRCS2   =       $(PATH3)my_lib.c  	\
		$(PATH3)my_assist.c	\
		$(PATH2)main.c    	\
		$(PATH2)glue_it.c	\
		$(PATH2)check.c		\

OBJS    =       $(SRCS:.c=.o)

OBJS2   =       $(SRCS2:.c=.o)

IFLAGS  =       -I ./includes/

CFLAGS  =       -W -Wall -Werror -Wextra $(IFLAGS)

CC      =       gcc -g

RM      =       rm -rf

all     :       $(NAME) $(NAME2)

$(NAME) :       $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIBS)

$(NAME2):       $(OBJS2)
		$(CC) -o $(NAME2) $(OBJS2) $(LIBS)

clean   :
		$(RM) $(OBJS)
		$(RM) $(OBJS2)

fclean  :       clean
		$(RM) $(NAME)
		$(RM) $(NAME2)

re      :       fclean all
