CFILES = fractol.c init.c render.c Utils.c
OFILES = $(CFILES:.c=.o)
NAME = fractol
CC = cc
CFLAGS1 = -Wall -Wextra -Werror
CFLAGS2 = -lmlx -framework OpenGL -framework AppKit -O3

all: $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS1) -c $< -o

$(NAME): $(OFILES)
	$(CC) $(CFLAGS2) -o $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) $(B_OFILES)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
