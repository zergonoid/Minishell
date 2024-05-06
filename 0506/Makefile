#.SILENT:
NAME = minishell
CC = cc

#libs
SRC_PATH =		./src/
SRC_FILES =		main.c 
SRC =			$(addprefix $(SRC_PATH), $(SRC_FILES))

LIBFT_PATH =	./libft/
LIBFT =			$(LIBFT_PATH)libft.a

CFLAGS =		-Wall -Wextra -Werror -g -fsanitize=address
OTHERFLAGS =	-L$(LIBFT_PATH) -lft -O3

OBJ_DIR =		./obj/
OBJS =			$(SRC:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)

#rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(OTHERFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/*
	@rmdir obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re