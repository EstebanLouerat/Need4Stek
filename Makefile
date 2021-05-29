##
## EPITECH PROJECT, 2021
## n4s_package
## File description:
## Makefile
##

PROJECT	=		N4S

SRC		=		$(wildcard source/*.c) $(wildcard source/lib/*.c)

NAME	=		ai

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-I./include


REDDARK	=	\e[31;2m
RED	=	\e[31;1m
GREEN	=	\e[32;1m
YEL	=	\e[33;1m
BLUE	=	\e[34;1m
PINK	=	\e[35;1m
CYAN	=	\e[36;1m
WHITE	=	\e[0m


all:	$(NAME)

debug:
	$(eval CFLAGS += -g3)
	@echo -ne "$(PINK)[DEBUG]$(WHITE)\n"
	@make BLUE='\033[35;1m' DEBUG='-g3' -s fclean $(NAME)

$(NAME):	start_compil $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "\n$(GREEN) → Successfully build.\n"

start_compil:
	@printf "\n$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)] — START BUILD\n\n"

clean:
	@printf "$(REDDARK)\nCleaning build files of \
	$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)]\n\n"
	@printf "$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)] — $(RED)%-45s\n" $(OBJ)
	@printf "\n$(GREEN) → $(RED) Build clean.\n\n$(WHITE)"
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

%.o:%.c
	@printf "$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)] — $(BLUE)%-30s" $@
	@echo -ne "$(WHITE)[$(GREEN)√$(WHITE)]\n"
	@gcc $(CFLAGS) -o $@ -c $<

.PHONY:	all clean fclean re