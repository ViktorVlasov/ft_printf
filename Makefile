# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/17 00:10:32 by efumiko           #+#    #+#              #
#    Updated: 2020/07/18 16:36:23 by efumiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ_DIR = obj/

FLAGS = -I$(INCLUDES_DIR) -Wall -Wextra -Werror
CC = clang

MAIN_DIR = main/
PARSER_DIR = parser/
PROCESSOR_DIR = processor/
UTILS_DIR = utils/

FILES_MAIN = ft_printf.o
FILES_PARSER = ft_parser.o ft_flags_parse.o ft_precision_parse.o \
				ft_type_parse.o ft_width_parse.o
FILES_PROCESSOR = ft_c_type.o ft_int_type.o ft_p_type.o ft_processor.o \
					ft_s_type.o ft_uxx_type.o
FILES_UTILS = ft_atoi.o ft_isdigit.o ft_putchar_n.o ft_putnbr.o ft_strlen.o

F_MAIN_D = $(addprefix $(OBJ_DIR), $(FILES_MAIN))
F_PARSER_D = $(addprefix $(OBJ_DIR), $(FILES_PARSER))
F_PROCESSOR_D = $(addprefix $(OBJ_DIR), $(FILES_PROCESSOR))
F_UTILS_D = $(addprefix $(OBJ_DIR), $(FILES_UTILS))

ALL_FILES_D = $(F_UTILS_D) $(F_MAIN_D) $(F_PARSER_D) $(F_PROCESSOR_D)

INC_MAIN = includes/ft_printf.h
INC_PARSER = includes/ft_parser.h
INC_PROCESSOR = includes/ft_processor.h
INC_UTILS = includes/ft_utils.h

all: $(NAME)

$(NAME): $(OBJ_DIR) all_o
	ar rc $(NAME) $(ALL_FILES_D)
	ranlib $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

all_o: $(F_UTILS_D) $(F_MAIN_D) $(F_PARSER_D) $(F_PROCESSOR_D)

$(F_UTILS_D): $(OBJ_DIR)%.o: $(UTILS_DIR)%.c $(INC_UTILS)
	$(CC) $(FLAGS) -c $< -o $@

$(F_MAIN_D): $(OBJ_DIR)%.o: $(MAIN_DIR)%.c $(INC_MAIN)
	$(CC) $(FLAGS) -c $< -o $@

$(F_PARSER_D): $(OBJ_DIR)%.o: $(PARSER_DIR)%.c $(INC_PARSER)
	$(CC) $(FLAGS) -c $< -o $@

$(F_PROCESSOR_D): $(OBJ_DIR)%.o: $(PROCESSOR_DIR)%.c $(INC_PROCESSOR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all all_o
