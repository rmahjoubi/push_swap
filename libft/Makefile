# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 23:14:05 by rmahjoub          #+#    #+#              #
#    Updated: 2019/10/07 18:21:24 by rmahjoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH_FT = srcs

SRC_PATH_PRINTF = printf/srcs

SRC_NAME_FT = ft_atoi.c\
			ft_bzero.c\
			ft_countlines.c\
			ft_getnline.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_isthere.c\
			ft_itoa.c\
			ft_lstadd.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_printnline.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putnchar.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			get_next_line.c\
			ft_toupper.c

SRC_NAME_PRINTF = floak.c\
			arithmtics.c\
			minimize_error.c\
			checknfill.c\
			fpoint_sign.c\
			more_extra_fun.c\
			decimal_mantissa.c\
			ft_printf.c\
			printf_putstrchr.c\
			e_spec.c\
			grep_mem.c\
			rm_uzeros_spec_g.c\
			extra_fun.c\
			insert_flgminuszeroprint.c\
			s_strjoin.c\
			extra_fun_f.c\
			insert_flgminuszeroprintt.c\
			special_printer.c\
			fill_arg0.c\
			insert_precision.c\
			fill_arg1.c\
			insrt_hash_spc_pls.c\
			filler.c\
			itoa_base.c

INC_PATH = -Iincludes -Iprintf/includes

FLAGS = gcc -Wall -Werror -Wextra

OBJ_PATH_FT = objs

OBJ_PATH_PRINTF = objs

OBJ_NAME_FT = $(SRC_NAME_FT:.c=.o)

OBJ_NAME_PRINTF = $(SRC_NAME_PRINTF:.c=.o)

SRC_FT = $(addprefix $(SRC_PATH_FT)/,$(SRC_NAME_FT))

SRC_PRINTF = $(addprefix $(SRC_PATH_PRINTF)/,$(SRC_NAME_PRINTF))

OBJ_FT = $(addprefix $(OBJ_PATH_FT)/,$(OBJ_NAME_FT))

OBJ_PRINTF = $(addprefix $(OBJ_PATH_PRINTF)/,$(OBJ_NAME_PRINTF))

all: $(NAME)

$(NAME): $(OBJ_FT) $(OBJ_PRINTF)
	ar rc $@ $^

$(OBJ_PATH_FT)/%.o: $(SRC_PATH_FT)/%.c
	@mkdir $(OBJ_PATH_FT) 2> /dev/null || true
	$(FLAGS) $(INC_PATH) -o $@ -c $<

$(OBJ_PATH_PRINTF)/%.o: $(SRC_PATH_PRINTF)/%.c
	@mkdir $(OBJ_PATH_PRINTF) 2> /dev/null || true
	$(FLAGS) $(INC_PATH) -o $@ -c $<

clean:
	rm -fv $(OBJ_FT) $(OBJ_PRINTF)
	@rmdir $(OBJ_PATH_FT) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

