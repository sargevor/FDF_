NAME = FDF

SRC =  src/camera.c src/draw.c src/fdf.c src/hooks.c src/limits.c src/points.c \
	  src/start.c gnlnew/get_next_line_utils.c gnlnew/get_next_line.c src/validation.c \
	  src/valutils.c src/valutils1.c src/valutils2.c src/valutils3.c src/valutils4.c src/main.c	\
	  src/hooksutil.c src/pointsutil.c src/pointsutil2.c

OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lX11 -lXext -lm -lbsd
INCLUDES = -Ignlnew -Ift_printf -Ilibft -I$(MLX_DIR)


CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C libft
	@make -C ft_printf
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)  libft/libft.a ft_printf/libftprintf.a $(MLX_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C $(MLX_DIR)
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	@rm -f $(NAME)
	@make clean -C $(MLX_DIR)
	@make fclean -C libft
	@make fclean -C ft_printf

re: fclean all

PHONY: all clean fclean re
