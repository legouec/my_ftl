##
## Makefile for  in 
## 
## Made by LEGOUEST Clement
## Login   <legoue_c@etna-alternance.net>
## 
## Started on  Wed Nov  8 10:35:41 2017 LEGOUEST Clement
## Last update Fri Nov 10 17:06:47 2017 LEGOUEST Clement
##

CC =			gcc
FLAGS =			-W -Wall -Werror -g3

SRCSLIBDIR =		srclib/
SRCSDIR=		src/
OBJSLIBDIR =		objlib/
OBJSDIR =		obj/
BINDIR =		bin/
LIBDIR =		lib/

SRCSLIB =		my_getnbr.c		\
			my_isneg.c		\
			my_put_nbr.c		\
			my_random.c		\
			my_strcat.c		\
			my_strcpy.c		\
			my_strlen.c		\
			my_strncat.c		\
			my_strncmp.c		\
			my_strncpy.c		\
			my_strstr.c		\
			my_swap.c		\
			my_string.c		\
			readline.c

SRCS =			main.c			\
			air_shed.c		\
			container.c		\
			system_control.c	\
			system_repair.c		\
			game_turns.c		\
			combat.c

OBJSLIB =		$(SRCSLIB:.c=.o)
OBJS =			$(SRCS:.c=.o)

LIBNAME =		libmy.a
NAME =			my_ftl
AR =			ar rc
RAN =			ranlib
RM =			rm -rf

$(BINDIR)$(NAME):       $(LIBDIR)$(LIBNAME)  $(addprefix $(OBJSDIR),$(OBJS)) 
			$(CC) -L lib/ $^ -o $@ -lmy -lm

$(OBJSDIR)%.o:          $(SRCSDIR)%.c
			$(CC) -I include/ $(FLAGS) -c $^ -o $@

$(LIBDIR)$(LIBNAME):	$(addprefix $(OBJSLIBDIR),$(OBJSLIB))
			$(AR) $@ $^
			$(RAN) $(LIBDIR)$(LIBNAME)

$(OBJSLIBDIR)%.o:	$(SRCSLIBDIR)%.c
			$(CC) -I include/ $(FLAGS) -c $^ -o $@

all:                    $(BINDIR)$(NAME)

clean:
			$(RM) $(addprefix $(OBJSLIBDIR),$(OBJSLIB)) $(addprefix $(OBJSDIR),$(OBJS))

fclean:			clean
			$(RM) $(LIBDIR)$(LIBNAME) $(BINDIR)$(NAME)

re:			fclean all

.PHONY:			all re clean fclean
