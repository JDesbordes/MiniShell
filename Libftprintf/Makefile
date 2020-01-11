# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/07 15:34:08 by jdesbord     #+#   ##    ##    #+#        #
#    Updated: 2019/12/09 14:22:01 by jdesbord    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#                                VARIABLES                                       #
# **************************************************************************** #

HEADER        =                    includes/ft_printf.h

LIB            =                    libft.a

LIBS        =                    Libft/libft.a

SRC_PATH    =                    sources

SRCS_NAME    =                     ft_printf.c fillflags.c ft_itoa_base.c\
									readflags.c fillflags2.c

OBJS        =                     ${SRCS:.c=.o}

NAME        =                     libftprintf.a

RM            =                     rm -f

FLAGS         =                     -Wall -Wextra -Werror

SRCS         =                     $(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#                                REGLES                                           #
# **************************************************************************** #

all:                            $(LIB) $(NAME)

bonus: all

%.o: %.c                         $(HEADER) $(LIBS)
	@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
	@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):                        $(OBJS) $(HEADER)
	@cp libft/libft.a ./$(NAME)
	@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Printf\033[0m"
	@ar rcs $(NAME) $(OBJS)

$(LIB):
	@$(MAKE) -C libft all

clean:
	@$(MAKE) -C libft clean
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
	@$(RM) $(OBJS)

fclean:                            clean
	@$(MAKE) -C libft fclean
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m"
	@$(RM) $(NAME)

re:                                fclean all

.PHONY:                         clean fclean
