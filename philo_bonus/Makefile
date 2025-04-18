NAME = philo_bonus

SRCS = philo_bonus.c ft_putchar_fd_bonus.c ft_putstr_fd_bonus.c ft_isdigit_bonus.c ft_atoi_bonus.c \
	parsing_bonus.c init_bonus.c clean_bonus.c timing_bonus.c philo_utils_bonus.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3  -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all