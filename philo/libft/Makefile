NAME    = libft.a

SOURCE    = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_strlen.c\
			ft_memchr.c ft_memcmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
			ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_atoi.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c\
			ft_atoll.c ft_error.c ft_null.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsort.c \

OBJ_SRC = $(patsubst %.c,%.o,$(SOURCE))
OBJ = $(addprefix obj/, $(SOURCE:.c=.o))

D_FILES = $(patsubst %.c,%.d,$(SOURCE) $(SOURCE_BONUS))

FLAGS = -Wall -Wextra -Werror 

.PHONY: all clean fclean re

all: obj/ $(NAME)

obj/ : 
	@mkdir obj

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

obj/%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -MMD

include $(wildcard $(D_FILES))

clean:
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all

