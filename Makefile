# Standard
NAME			= push_swap

# Directories
LIBFT			= ./libft/libft.a
INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compielr and Flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC)
RM				= rm -f
AR				= ar rcs

# Source Files
COMMANDS_DIR	=	$(SRC_DIR)commands/push.c \
				$(SRC_DIR)commands/rev_rotate.c \
				$(SRC_DIR)commands/rotate.c \
				$(SRC_DIR)commands/swap.c \

PUSH_SWAP_UTILS	=	$(SRC_DIR)errors.c \
				$(SRC_DIR)init_a_to_b.c \
				$(SRC_DIR)init_b_to_a.c \
				$(SRC_DIR)split.c \
				$(SRC_DIR)stack_init.c \
				$(SRC_DIR)stack_utils.c \
				$(SRC_DIR)turk_algorithm.c \
				$(SRC_DIR)sort_three.c \
				$(SRC_DIR)calc_cost.c
			
PUSH_SWAP	=	$(SRC_DIR)push_swap.c \

# Concatenate all source files
SRCS 			= $(COMMANDS_DIR) $(PUSH_SWAP_UTILS) $(PUSH_SWAP)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
				@make all

$(LIBFT):
				@make -C ./libft

all: 			$(NAME)

$(NAME): 		$(OBJ) $(LIBFT)
				@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)
				@make clean -C ./libft

fclean: 		clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		start all clean fclean re
