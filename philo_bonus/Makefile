NAME = philo_bonus

CC = gcc

CFLAGS =  -O2 -Wall -Wextra -Werror

SRC_DIR = ./

PHILO_FILES = main.c get_time.c init.c simulation.c \
				output.c

OBJ_DIR = obj/

PHILO_OBJ_FILES = $(patsubst %.c,%.o,$(PHILO_FILES))

PHILO_OBJ = $(addprefix $(OBJ_DIR), $(PHILO_OBJ_FILES))

HEADER = philo.h

LIBFT_DIR = libft

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR): 
			mkdir $(OBJ_DIR)

$(NAME): $(PHILO_OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(PHILO_OBJ) libft/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

bonus : all

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all