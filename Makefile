NAME			=	push_swap

NAME_BONUS		=	checker

LIBFT			=	libft.a

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c actions.c actions_utils.c lis.c misc.c print.c price.c math.c

SRCS_NAMES_B	=	checker.c actions.c actions_utils.c lis.c misc.c print.c price.c math.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD			=	-I includes

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

all				:	${NAME}

$(NAME): $(OBJS)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} -o $(NAME)
	@echo "\033[34;5mpushswap\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

bonus:
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(SRCS_B) ${LIBFT} -o $(NAME_BONUS)
	@echo "\033[34;5mpushswap\033[0m"

clean:
	make clean -C libft
	rm -rf ${DIR_OBJS}
	rm -rf ${OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}

re:	fclean all

stop:
	rm ${NAME}

.PHONY:	all clean fclean re bonus
