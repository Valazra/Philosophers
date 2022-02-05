NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread #-g -fsanitize=thread

SRCS_DIR = srcs
INC_DIR = includes

INCLUDES = $(INC_DIR)/philo.h
SRCS = main.c

SRC = $(addprefix srcs/, $(SRCS))

OBJS = = $(SRC:.c=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: make, all, clean, fclean, re
