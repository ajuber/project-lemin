# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 14:28:27 by ajubert           #+#    #+#              #
#    Updated: 2016/09/02 04:04:25 by ajubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		lem-in
COMPILER=	gcc
FLAG=		-g -Wall -Werror -Wextra
LIB=		libft.a
INCLUDES=	-I ./libft/includes/
vpath %.c

SRC_C=	main.c\
		recup_salle.c\
		is_infos.c\
		free_line.c\
		ft_print_liaison.c\
		ft_print_salle.c\
		get_coor.c\
		get_salle.c\
		is_liaison.c\
		recup_liaison.c\
		recup_nb_ant.c\
		list.c\
		convert_liaison.c\
		ft_print_convert_liaison.c\
		add_infos.c\
		no_start_no_end.c\
		create_chemin.c\
		ft_print_chemin.c\
		list1.c\
		liste_chemin.c\
		add_salle.c\
		check_liaison.c\
		chemin_valid.c\
		del_last_salle.c\
		new_chemin.c

SRC_O=		$(SRC_C:.c=.o)

all: libft.h libft.a $(NAME)

$(NAME): $(SRC_O)
	$(COMPILER) -o $(NAME) $(SRC_O) $(LIB) $(FLAG)
	@echo "\033[32m=======FILLER HAS BEEN CREATED=======\033[0m"

%.o: %.c
	$(COMPILER) $(FLAG) -c $(subst __,/,$<) -o $@

libft.a:
	@echo "\033[32m==================================="
	@echo "==========COMPILING LIBFT=========="
	@echo "===================================\033[0m"
	make re -C ./libft/
	cp ./libft/libft.a .
	make fclean -C ./libft/

libft.h:
	cp ./libft/libft/libft.h .
	cp ./libft/libft/get_next_line.h .
	cp ./libft/printf/ft_printf.h .

clean:
	@echo "\033[33m==========REMOVING OBJ FILES==========\033[0m"
	rm -rf $(SRC_O)

fclean: clean
	@echo "\033[31m==========REMOVING BIN FILES==========\033[0m"
	rm -rf $(NAME) libft.a
	rm -rf libft.h
	rm -rf get_next_line.h
	rm -rf ft_printf.h

re: fclean all
