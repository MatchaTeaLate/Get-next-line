# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 11:26:01 by anovikav          #+#    #+#              #
#    Updated: 2021/12/21 15:31:16 by anovikav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c	\

BONUS =	get_next_line_bonus.c get_next_line_utils_bonus.c	\

CC = gcc

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf 

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.0)

$(NAME): $(OBJ)
	ar -rc get_next_line.a $(OBJ)

bonus: $(OBJ) $(BONUS)
	ar -rc get_next_line.a $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all