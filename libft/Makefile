# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 13:41:32 by anestor           #+#    #+#              #
#    Updated: 2018/03/08 23:25:20 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = 
ODIR = bin/
OBJ = $(SRC:.c=.o)
EXT = libft.h
SRC = 

SRC += ft_strcat.c
SRC += ft_strcmp.c
SRC += ft_strdup.c
SRC += ft_striteri.c
SRC += ft_strlen.c
SRC += ft_strncat.c
SRC += ft_strnequ.c
SRC += ft_strsplit.c
SRC += ft_strtrim.c
SRC += ft_strchr.c
SRC += ft_strcpy.c
SRC += ft_strequ.c
SRC += ft_strjoin.c
SRC += ft_strmap.c
SRC += ft_strncmp.c
SRC += ft_strnew.c
SRC += ft_strstr.c
SRC += ft_strnstr.c
SRC += ft_strclr.c
SRC += ft_strdel.c
SRC += ft_striter.c
SRC += ft_strlcat.c
SRC += ft_strmapi.c
SRC += ft_strncpy.c
SRC += ft_strrchr.c
SRC += ft_strsub.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isprint.c
SRC += ft_isalpha.c
SRC += ft_toupper.c
SRC += ft_tolower.c
SRC += ft_atoi.c
SRC += ft_itoa.c
SRC += ft_bzero.c
SRC += ft_isalnum.c
SRC += ft_putchar.c
SRC += ft_putchar_fd.c
SRC += ft_putendl.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr.c
SRC += ft_putnbr_fd.c
SRC += ft_putstr.c
SRC += ft_putstr_fd.c
SRC += ft_memalloc.c
SRC += ft_memccpy.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memdel.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_lstnew.c
SRC += ft_lstdelone.c
SRC += ft_lstdel.c
SRC += ft_lstadd.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_atoi_base.c
SRC += ft_itoa_base.c
SRC += ft_uitoa_base.c
SRC += ft_isspace.c
SRC += ft_isbase.c
SRC += ft_strtrim_char.c
SRC += ft_invert_char.c
SRC += ft_putstr_col.c
SRC += ft_lstadd_back.c
SRC += ft_sqrt.c
SRC += get_next_line.c
SRC += ft_strrmap.c
SRC += ft_printf.c
SRC += ft_printf_sub.c
SRC += ft_printf_chars.c
SRC += ft_printf_nums.c
SRC += ft_printf_make_params.c
SRC += ft_printf_kostyl.c
SRC += ft_count_words.c
SRC += ft_num_len.c
SRC += ft_itoa_base_int.c
SRC += ft_txy.c
SRC += ft_make_array.c
SRC += ft_make_matrix.c
SRC += ft_del_matrix.c
SRC += ft_copy_matrix.c

O = $(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O) $(EXT)
#	@echo " ░       \033[96mcompiling libft\033[0m       ░ "
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c $(EXT)
	@echo "... compiling $< ..."
	@gcc $(FLAGS) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir $(ODIR)

clean:
	@echo "... cleaning libft obj ..."
	@rm -rf bin/

fclean: clean
	@echo "... cleaning $(NAME) ..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
