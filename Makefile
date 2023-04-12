# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:25:02 by abez-zir          #+#    #+#              #
#    Updated: 2023/03/21 14:25:07 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME	= server
NAME_C	= client
NAME_bs	= server_bonus
NAME_C_bs	= client_bonus
# **************************************************************************
UTILs	= utils.c
OBJ_U = $(UTILs:.c=.o)

# **************************************************************************
SRC_client  = client.c
SRC_server  = server.c
SRC_client_bs  = client_bonus.c
SRC_server_bs  = server_bonus.c

# **************************************************************************
OBJ_client = $(SRC_client:.c=.o)
OBJ_server = $(SRC_server:.c=.o)

# **************************************************************************
OBJ_server_bs = $(SRC_server_bs:.c=.o)
OBJ_client_bs = $(SRC_client_bs:.c=.o)

# **************************************************************************
%.o:%.c Minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************
all: $(NAME) $(NAME_C)

# **************************************************************************
$(NAME) : $(OBJ_server) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_server) -o $(NAME)

$(NAME_C) : $(OBJ_client) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_client) -o $(NAME_C)

# **************************************************************************
bonus: $(NAME_bs) $(NAME_C_bs)

# **************************************************************************
$(NAME_bs) : $(OBJ_server_bs) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_server_bs) -o $(NAME_bs)

$(NAME_C_bs) : $(OBJ_client_bs) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_client_bs) -o $(NAME_C_bs)

# **************************************************************************
clean:
	rm -rf $(OBJ_client_bs) $(OBJ_server_bs)
	rm -rf $(OBJ_client) $(OBJ_server)

fclean: clean
	rm -rf $(NAME) $(NAME_C) $(OBJ_U)
	rm -rf server_bonus client_bonus

re: fclean all
