DIR_SRC			= ./src/
DIR_INC			= ./includes/
DIR_LIB			= ./libft/
DIR_OBJ 		= ./obj/

FILE_LS		= \
			  ft_ls \
			  add_new_file \
			  display \
			  parse \
			  sorting

SRC_LS 	= $(addprefix $(DIR_SRC), $(addsuffix .c, $(FILE_LS)))
OBJ_LS 	= $(addprefix $(DIR_OBJ), $(addsuffix .o, $(FILE_LS)))

CC 	   			= gcc
FT_LS 			= ft_ls
#CFLAGS 	   		= -Wall -Werror -Wextra -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)
CFLAGS 	   		= -O2 -I$(DIR_INC) -I$(DIR_LIB)$(DIR_INC)

all: ft_ls

lib:
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

ft_ls: $(DIR_OBJ) $(OBJ_LS) lib
	@$(CC) $(CFLAGS) -o $(FT_LS) $(OBJ_LS) $(DIR_LIB)libft.a

clean:
	@make clean -C $(DIR_LIB)
	@rm -rf $(DIR_OBJ)

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(FT_LS)

re: fclean all

.PHONY: all clean fclean re
