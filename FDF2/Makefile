NAME		= fdf
SRC			= SRC/*.c
CUR			= fdf2.c
OBJ			= $(SRC:%.c=%.o)
OBJC		= $(CUR:%.c=%.o)
CC			= gcc
LIBPATH		= SRC/libft/
HEADERDIR	= SRC/INCLUDES/

all		: $(NAME)

#Macos
$(OBJ)	: $(SRC)
		make bonus -C $(LIBPATH)
#		make -C mlx_mms_20191025
		make -C minilibx_macos
		$(CC) -Wall -Werror -Wextra -Imlx -c $(SRC) -I$(HEADERDIR)
		mv *.o SRC/

# Convert the main to .o on the main place
$(OBJC)	: $(CUR)
		$(CC) -Wall -Werror -Wextra -Imlx -c $(CUR) -I$(HEADERDIR)

$(NAME)	: $(OBJ) $(OBJC)
		$(CC) -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit $^ $(LIBPATH)libft.a -o $(NAME)

#LINUX - ubuntu
#$(OBJ)  : $(SRC)
#		$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -g -O3 -c $< -o $@

#$(NAME) : $(OBJ)
#		$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean	:
		rm -rf $(OBJ) $(OBJC)
		make clean -C $(LIBPATH)
#		make clean -C mlx_mms_20191025
		make clean -C minilibx_macos

fclean	: clean
		rm -rf $(NAME)
		make fclean -C $(LIBPATH)
#		make clean -C mlx_mms_20191025
		make clean -C minilibx_macos

re		: fclean all
		make re -C $(LIBPATH)

.PHONY	: all clean fclean re
