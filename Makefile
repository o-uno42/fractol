CC = gcc
CFLAGS = -Wall -Wextra -Werror -Lminilibx-linux -lml -lX11 -lXext -lm -g
NAME = fractol.a

FILES_SRCS = fractol.c colors.c win_manage.c utils.c julia.c mandelbrot.c utils2.c utils3.c

FILES_OBJS = $(FILES_SRCS:.c=.o)

HEADER = fractol.h

EXECUTABLE = fractol

all: $(NAME) $(EXECUTABLE)

$(NAME): $(FILES_OBJS)
		ar rc $(NAME) $(FILES_OBJS)
		ranlib $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(FILES_OBJS)
		$(CC) -o $(EXECUTABLE) $(FILES_OBJS) -Lminilibx-linux -lmlx -lX11 -lXext -lm

clean:
		rm -f $(FILES_OBJS)

fclean: clean
		rm -f $(NAME) $(EXECUTABLE)

re: fclean all


