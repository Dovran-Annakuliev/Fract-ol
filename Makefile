# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 17:09:20 by rfork             #+#    #+#              #
#    Updated: 2020/03/18 18:28:24 by dovran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -g
NAME = fractol
SRCS = sources/main.c\
		sources/start.c\
		sources/errors.c\
		sources/read_arg.c\
		sources/fractol.c\
		sources/draw_image.c\
		sources/key.c
OBJS = $(SRCS:.c=.o)
HEAD = -c -I includes\fractol.h\
				includes\key.h

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	#LIB += -L./libs/glad/ -lglad -ldl  -lGL -L./libs/glfw/src/ -lglfw3 \
	-lXrandr -lXrender -lXi -lXfixes -lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp
	LIBMAKE := minilibx/minilibx
	LIB :=  -L libft -lft -L minilibx/minilibx -lmlx_Linux  -lXrandr -lXrender -lXi -lXfixes \
	-lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lm
endif
ifeq ($(detected_OS),Darwin)  
	#LIB = -L./libs/glad/ -lglad -L./libs/glfw/src/ -lglfw3      # Mac OS X
	#LIBRARIES += -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
	LIBMAKE := minilibx/minilibx_macos
	LIB = -L libft -lft -L minilibx/minilibx -lmlx -framework OpenGL -framework Appkit
endif

all: $(NAME)

%.o: %.c
		$(GCC) -c $<

lib:
		make -C libft
		make -C minilibx/minilibx

$(NAME): $(OBJS) lib
		 $(GCC) $(OBJS)  $(LIB)   -o $(NAME)

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean: clean
		rm -f $(NAME)
		make -C libft fclean
		make -C minilibx/minilibx clean

re: fclean all
