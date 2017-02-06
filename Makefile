#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/08 21:26:14 by gboudrie          #+#    #+#              #
#    Updated: 2017/02/03 14:14:17 by gboudrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = rtv1

MKLIB = make -C libft/

INCLUDES = libft/libft.a

CC = gcc

HEADER = src/rtv1.h

FLAGS = -Wall -Wextra -Werror -Ofast

SOURCES = src/main.c \
			src/parser.c \
			src/raytracer.c \
			src/set_structs.c \
			src/collide.c \
			src/rotation.c \
			src/vectors.c \
			src/vectors2.c \

OBJS = $(SOURCES:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all :			$(NAME)

$(NAME) :		$(OBJS) $(HEADER) Makefile
				$(MKLIB)
				$(CC) $(FLAGS) -c $(SOURCES)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)


fonly :
				$(CC) $(FLAGS) -c $(SOURCES)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)

norm :
				norminette $(SOURCES)

meteo :
				curl http://wttr.in/Paris
				curl http://wttr.in/Moon

clean :
				-rm -f $(OBJS)

fclean :		clean
				$(MKLIB) fclean
				-rm -f $(NAME)

re :			fclean all

