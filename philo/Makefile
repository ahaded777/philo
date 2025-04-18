NAME = philo

SRCS = philo.c ft_putchar_fd.c ft_putstr_fd.c ft_isdigit.c ft_atoi.c \
	parsing.c init.c clean.c timing.c philo_utils.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -g3  -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all