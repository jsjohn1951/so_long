# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 19:47:17 by wismith           #+#    #+#              #
#    Updated: 2022/04/22 19:36:01 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

.SILENT:

SRCS = so_long errors/msg parser/parser\
		window/key_manage window/start\
		window/Objs window/moves\
		errors/errcheck window/is_collectable\
		errors/freedom errors/errcheck2\
		errors/msg2 window/terminate\

SRCSB = so_long_bonus errors_bonus/msg_bonus parser_bonus/parser_bonus\
		window_bonus/key_manage_bonus window_bonus/start_bonus\
		window_bonus/Objs_bonus window_bonus/moves_bonus\
		errors_bonus/errcheck_bonus window_bonus/is_collectable_bonus\
		errors_bonus/freedom_bonus errors_bonus/errcheck2_bonus\
		errors_bonus/msg2_bonus window_bonus/terminate_bonus\
		window_bonus/Objs2_bonus

OBJ_DIR = assets/OBJECTS
OBJB_DIR = assets/OBJECTS_BONUS
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))
OBJB = $(addprefix $(OBJB_DIR)/, $(addsuffix .o, $(SRCSB)))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = assets/mlx
LIBFT = assets/libft
LIBFTARCH = assets/libft/Library/libft.a

$(OBJ_DIR)/%.o: srcs/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJB_DIR)
	mkdir -p $(OBJ_DIR)/errors
	mkdir -p $(OBJ_DIR)/parser
	mkdir -p $(OBJ_DIR)/window
	mkdir -p $(OBJB_DIR)/errors_bonus
	mkdir -p $(OBJB_DIR)/parser_bonus
	mkdir -p $(OBJB_DIR)/window_bonus
	$(CC) $(CFLAGS) -I $(MLX) -c $< -o $@

$(OBJB_DIR)/%.o: srcs/%.c
	mkdir -p $(OBJB_DIR)
	mkdir -p $(OBJB_DIR)/errors_bonus
	mkdir -p $(OBJB_DIR)/parser_bonus
	mkdir -p $(OBJB_DIR)/window_bonus
	$(CC) $(CFLAGS) -I $(MLX) -c $< -o $@

all: $(NAME)
	tput setaf 3
	echo ""
	echo "->" | tr -d '\n'
	tput setaf 2
	echo " all provided " | tr -d '\n'
	tput setaf 3
	echo "<-"
	echo ""
	tput setaf 7
	echo "SO_LONG: 'You may now run the executable'\n"

$(NAME): $(OBJ)
	make -C $(MLX)
	printf "\e[1;1H\e[2J"
	tput setaf 7
	echo "SO_LONG: 'Building Libft may require a moment'\n"
	make -C $(LIBFT)
	@tput setaf 3; echo "\nASSETS->"
	@tput setaf 3; echo "Building->"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTARCH) -L $(MLX) -l mlx -framework OpenGL -framework AppKit -o $(NAME)
	rm -r -f Objects

bonus: $(OBJB)
	make -C $(MLX)
	printf "\e[1;1H\e[2J"
	tput setaf 7
	echo "SO_LONG: 'Building Libft may require a moment'\n"
	make -C $(LIBFT)
	@tput setaf 3; echo "\nASSETS->"
	@tput setaf 3; echo "Building->"
	$(CC) $(CFLAGS) $(OBJB) $(LIBFTARCH) -L $(MLX) -l mlx -framework OpenGL -framework AppKit -o so_long_bonus
	rm -r -f Objects
	tput setaf 7
	echo "\nSO_LONG: 'You may now run the BONUS executable'\n"

clean:
	make clean -C $(MLX)
	make clean -C $(LIBFT)
	rm -f $(OBJ) $(OBJB)
	rm -r -f $(OBJ_DIR) $(OBJB_DIR)

fclean : clean
	make fclean -C $(MLX)
	make fclean -C $(LIBFT)
	rm -f $(NAME)
	rm -f so_long_bonus

re : fclean all

.PHONY: all clean fclean re bonus
