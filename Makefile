# Standard
NAME			= push_swap

# Directories
LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a
INC			= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compielr and Flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC) -I$(LIBFT_DIR)/inc
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

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJ)
			@echo "Linking $(NAME)..."
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "Build complete!"

# Check if libft directory exists, if not clone it
$(LIBFT_DIR):
			@echo "libft not found. Cloning from repository..."
			@git clone git@github.com:rceliows/libft.git $(LIBFT_DIR)
			@echo "libft cloned successfully!"

$(LIBFT):		$(LIBFT_DIR)
			@echo "Building libft..."
			@make -C $(LIBFT_DIR)
			@echo "libft built successfully!"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@echo "Cleaning object files..."
			@$(RM) -r $(OBJ_DIR)
			@if [ -d "$(LIBFT_DIR)" ]; then make clean -C $(LIBFT_DIR); fi
			@echo "Clean complete!"

fclean:			clean
			@echo "Removing executables..."
			@$(RM) $(NAME)
			@if [ -d "$(LIBFT_DIR)" ]; then $(RM) $(LIBFT); fi
			@echo "Full clean complete!"

fcleanall:		fclean
			@echo "Removing library directories..."
			@if [ -d "$(LIBFT_DIR)" ]; then rm -rf $(LIBFT_DIR); echo "Removed $(LIBFT_DIR)"; fi
			@echo "Full clean with libraries complete!"

re:			fclean all

reall:			fcleanall all

# Phony targets represent actions not files
.PHONY:			all clean fclean fcleanall re reall
