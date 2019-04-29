# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 14:48:42 by kkuvalis          #+#    #+#              #
#    Updated: 2019/04/28 15:33:20 by kkuvalis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC  = main.c get_next_line.c

OBJ  = $(SRC:.c=.o)

FLAGS =  -g -Wall -Werror -Wextra

FLAGS_MLX = -lmlx -lXext -lX11

LIBFT = libft/libft.a

INC_LIB = libft

HEAD = libft/libft.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -I$(INC_LIB) -o $(NAME)  -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
	
$(LIBFT):
	make -C libft/

%.o : %.c fdf.h 
	gcc $(FLAGS) -c $< -o $@ -I$(INC_LIB)

clean:
	make -C libft clean
	rm -f *.o

fclean: clean
	make -C libft fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
	make -C libft re
