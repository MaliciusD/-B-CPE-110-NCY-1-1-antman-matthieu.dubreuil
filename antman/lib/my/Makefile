##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

NAME	=	libmy.a

RM		=	rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I /lib/include/my.h
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	cp libmy.a ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../libmy.a

re: fclean all

.PHONY: all clean fclean re
