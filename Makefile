# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jdesbord <jdesbord@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/07 15:34:08 by jdesbord     #+#   ##    ##    #+#        #
#    Updated: 2020/01/13 07:32:05 by jdesbord    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

HEADER		=			includes/minishell.h

LIB			=			libftprintf.a

LIBS		=			Libftprintf/libftprintf.a

SRC_PATH	=			srcs

SRCS_NAME	=			minishell.c ft_echo.c ft_setup.c ft_input.c ft_cd.c ft_env.c ft_parseargs.c

OBJS        =			${SRCS:.c=.o}

NAME		=			minishell

RM			=			rm -f

FLAGS		=			-g3 -fsanitize=address

SRCS		=			$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#                                REGLES                                        #
# **************************************************************************** #

all:                            $(NAME)

bonus: all

%.o: %.c                         $(HEADER) $(LIBS)
						@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
						@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):				$(LIB) ART $(OBJS) $(HEADER)
						@gcc $(OBJS) $(FLAGS) $(LIBS) -o $(NAME) -lm
						@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Cube3D\033[0m"

$(LIB):
								@$(MAKE) -C Libftprintf all

clean:
								@$(MAKE) -C Libftprintf clean
								@echo "\x1b[36m[OK] \033[0m \x1b[34m Removing ALL File object\033[0m"
								@$(RM) $(OBJS)

fclean:                         clean
								@$(MAKE) -C Libftprintf fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[32m All is Removing\033[0m"
								@$(RM) $(NAME)

re:                                fclean all

ART:
			@echo "___  ________ _   _ _____ _____ _   _  _____ _      _     "
			@echo "|  \/  |_   _| \ | |_   _/  ___| | | ||  ___| |    | |    "
			@echo "| .  . | | | |  \| | | | \ '--.| |_| || |__ | |    | |    "
			@echo "| |\/| | | | | . ' | | |  '--. \  _  ||  __|| |    | |    "
			@echo "| |  | |_| |_| |\  |_| |_/\__/ / | | || |___| |____| |____"
			@echo "\_|  |_/\___/\_| \_/\___/\____/\_| |_/\____/\_____/\_____/"
			@echo ""
                                                          

.PHONY:                         clean fclean
