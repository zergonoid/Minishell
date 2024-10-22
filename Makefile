#.SILENT:
NAME = minishell
CC = cc

#paths
SRC_PATH =		./src/
SRC_FILES =		main.c \
				reset_msh.c \
				init.c \
				error.c \
				signals.c \
				parser.c \
				utils/gen_utils.c \
				utils/envp_utils.c \
				utils/lst_utils.c \
				utils/parser_utils.c \
				lexer/lexer.c \
				lexer/handlers.c \
				builtins/builtin_select.c \
				builtins/builtin_cd.c \
				builtins/builtin_echo.c \
				builtins/builtin_env.c \
				builtins/builtin_exit.c \
				builtins/builtin_export.c \
				builtins/builtin_pwd.c \
				builtins/builtin_unset.c \
				
SRC =			$(addprefix $(SRC_PATH), $(SRC_FILES))

LIBFT_PATH =	./libft/
LIBFT =			$(LIBFT_PATH)libft.a

CFLAGS =		-Wall -Wextra -Werror -g #-fsanitize=address -lasan -O3
RLFLAGS =		-lreadline -lhistory
LFLAGS =		-L$(LIBFT_PATH) -lft

LXR_DIR = 		./lexer/
BLT_DIR	=		./builtins/
UTL_DIR = 		./utils/
OBJ_DIR =		./obj/
OBJS =			$(addprefix $(OBJ_DIR), $(patsubst $(SRC_PATH)%.c, %.o, $(SRC)))

#rules
all: $(NAME)

$(NAME): $(OBJS)
	@make -sC libft/
	@$(CC) $(CFLAGS) $(OBJS) $(RLFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(LXR_DIR)
	@mkdir -p $(OBJ_DIR)$(BLT_DIR)
	@mkdir -p $(OBJ_DIR)$(UTL_DIR)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)/*
	@make clean -sC libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re
