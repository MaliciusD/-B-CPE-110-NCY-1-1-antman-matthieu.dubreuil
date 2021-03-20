##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

all:
	$(MAKE) -C ./antman
	$(MAKE) -C ./giantman

clean:
	(cd antman/ ; make fclean)
	(cd giantman/ ; make fclean)

fclean: clean

re: fclean all

.PHONY: all clean fclean re