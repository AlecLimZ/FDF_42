NAME		= fdf
SRC			= SRC/*.c
CUR			= fdf2.c
OBJ			= $(SRC:%.c=%.o)
OBJC		= $(CUR:%.c=%.o)
CC			= gcc
LIBPATH		= SRC/libft/

all		: $(NAME)

#Macos
$(OBJ)	: $(SRC)
		make bonus -C $(LIBPATH)
		make -C mlx_mms_20191025
		$(CC) -Wall -Werror -Wextra -Imlx -c $(SRC)
		mv *.o SRC/

$(OBJC)	: $(CUR)
		$(CC) -Wall -Werror -Wextra -Imlx -c $(CUR)

$(NAME)	: $(OBJ) $(OBJC)
		$(CC) -Lmlx_mms_20191025 -lmlx -framework OpenGL -framework AppKit $^ $(LIBPATH)libft.a -o $(NAME)

#LINUX - ubuntu
#$(OBJ)  : $(SRC)
#		$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -g -O3 -c $< -o $@

#$(NAME) : $(OBJ)
#		$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean	:
		rm -rf $(OBJ) $(OBJC)
		make clean -C $(LIBPATH)
		make clean -C mlx_mms_20191025

fclean	: clean
		rm -rf $(NAME)
		make fclean -C $(LIBPATH)
		make clean -C mlx_mms_20191025

re		: fclean all
		make re -C $(LIBPATH)

.PHONY	: all clean fclean re
