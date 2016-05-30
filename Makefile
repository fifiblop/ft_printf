# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:22:44 by pdelefos          #+#    #+#              #
#    Updated: 2016/05/28 15:05:12 by pdelefos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

SRC_PATH = src
SRC_NAME = ft_printf.c parse_format.c parse_options.c print_format.c print_c.c \
		   print_str.c print_s_decimal.c print_u_decimal.c print_u_octal.c \
		   print_u_hexa.c print_ptr.c print_percent.c test_flags.c \
		   ft_itoa_base_ll.c ft_itoa_base_ull.c ft_putnchar.c ft_putwchar.c \
		   min_width.c add_accuracy_options.c length_modifier.c tools.c \
		   ft_putwstr.c print_wchar.c print_wstr.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH)/)

NO_COLOR = \x1b[0m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
MAGENTA = \x1b[35;01m

all: makelibft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@libtool -static -o $@ $^
	@echo "$(GREEN)libtool$(NO_COLOR) -static -o $(MAGENTA)>>$(NO_COLOR) $(OBJ_PATH) $(LIBFT) $(MAGENTA)>>$(NO_COLOR) $(NAME)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(GREEN)CC$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $< $(MAGENTA)>>$(NO_COLOR) $@"

makelibft:
	@make -C libft/

clean: 
	@rm -f $(OBJ)
	@echo "$(RED)RM >>$(NO_COLOR) $(OBJ_PATH)"
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)RM >>$(NO_COLOR) $(NAME)"

gfclean: fclean
	make fclean -C libft

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/libft.h
	norminette $(INC_PATH)/printf.h

.PHONY: all clean fclean gfclean re norme
