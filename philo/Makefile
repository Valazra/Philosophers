NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread #-g -fsanitize=thread

SRCS_DIR = srcs
INC_DIR = includes

INC = -I$(INC_DIR)
INCLUDES = $(INC_DIR)/philo.h

SRCS = main.c errors.c utils.c init_and_check.c threads.c loop.c time.c statut.c

SRC = $(addprefix srcs/, $(SRCS))

OBJS = $(SRC:.c=.o)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: make, all, clean, fclean, re
