CFILES = fractol.c init.c math_utils.c render.c
OFILES = $(CFILES:.c=.o)
NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra 

all: $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) $(B_OFILES)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
