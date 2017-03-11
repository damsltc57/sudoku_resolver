##
## Makefile for Makefile in /home/dams/delivery/CPE/CPE_2016_matchstick/
##
## Made by Damien Laurent
## Login   <damien.laurent@epitech.eu@epitech.eu>
##
## Started on  Mon Feb 13 18:13:54 2017 Damien Laurent
## Last update Sat Mar 11 17:59:49 2017 Damien Laurent
##

SRCS		=		solver.c		\
						checker.c		\
						get_next_line.c		\
						openfile.c

OBJ		=		$(SRCS:.c=.o)

NAME		=		solver

CC		=		gcc -g -O3 -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
