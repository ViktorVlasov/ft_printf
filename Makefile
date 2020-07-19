# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/17 00:10:32 by efumiko           #+#    #+#              #
#    Updated: 2020/07/19 09:34:48 by efumiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES_DIR = includes/

FLAGS = -I$(INCLUDES_DIR) -Wall -Wextra -Werror

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

F_MAIN_D = $(addprefix $(MAIN_DIR), $(FILES_MAIN))
F_PARSER_D = $(addprefix $(PARSER_DIR), $(FILES_PARSER))
F_PROCESSOR_D = $(addprefix $(PROCESSOR_DIR), $(FILES_PROCESSOR))
F_UTILS_D = $(addprefix $(UTILS_DIR), $(FILES_UTILS))

INC_MAIN = includes/ft_printf.h
INC_PARSER = includes/ft_parser.h
INC_PROCESSOR = includes/ft_processor.h
INC_UTILS = includes/ft_utils.h

all: $(NAME)

$(NAME): $(F_UTILS_D) $(F_MAIN_D) $(F_PARSER_D) $(F_PROCESSOR_D)
	ar rc $(NAME) $^
	ranlib $(NAME)

$(F_UTILS_D): $(UTILS_DIR)%.o: $(UTILS_DIR)%.c $(INC_UTILS)
	$(CC) $(FLAGS) -c $< -o $@

$(F_MAIN_D): $(MAIN_DIR)%.o: $(MAIN_DIR)%.c $(INC_MAIN)
	$(CC) $(FLAGS) -c $< -o $@

$(F_PARSER_D): $(PARSER_DIR)%.o: $(PARSER_DIR)%.c $(INC_PARSER)
	$(CC) $(FLAGS) -c $< -o $@

$(F_PROCESSOR_D): $(PROCESSOR_DIR)%.o: $(PROCESSOR_DIR)%.c $(INC_PROCESSOR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(F_UTILS_D) $(F_MAIN_D) $(F_PARSER_D) $(F_PROCESSOR_D)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all all_o
