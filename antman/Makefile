##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

NAME	=	antman

CC		=	gcc

RM		=	rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

CFLAGS  =	-I /include/my.h
CFLAGS +=	-Wextra -W -Wall -g

LDFLAGS += -Llib/ -lmy

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	 (cd ./lib/my/; make fclean)
	 $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re