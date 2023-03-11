SRCS = so_long.c srcs/error.c validation/validation.c \
validation/validation3.c validation/validation2.c  srcs/ft_split.c \
srcs/get_next_line.c srcs/get_next_line_utils.c srcs/ft_strdup.c \
srcs/ft_itoa.c movement/movment.c movement/movemnet2.c srcs/ft_printf.c



OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.

NAME			= so_long

# MLX				= minilibx/library/libmlx.a

# %.o : %.c :
# 		$(CC) $(CFLAGS) -c $< -o $^

all:		1337_logo	$(NAME) 

# $(MLX)			: 
# 					@make -C minilibx

$(NAME):	1337_logo	$(OBJS)
				cc -lmlx -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

clean:
				@$(RM) $(OBJS) 

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

1337_logo:

	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m███╗░░░███╗███████╗██████╗░"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m████╗░████║██╔════╝██╔══██╗"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m██╔████╔██║█████╗░░██║░░██║"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m██║╚██╔╝██║██╔══╝░░██║░░██║"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m██║░╚═╝░██║███████╗██████╔╝"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m╚═╝░░░░░╚═╝╚══════╝╚═════╝░"
	@echo "\033[92mCREATING .O FILES AND SO_LONG✅\033[0m"

.PHONY: all fclean clean test 1337_logo


# OBJS			= $(SRCS:.c=.o)
# CC				= gcc
# RM				= rm -rf
# CFLAGS			= -g -Wall -Wextra -Werror -I.
# NAME			= so_long
# MLX				= minilibx/library/libmlx.a


# $(MLX)			: 
# 					make -C minilibx

# $(NAME):		$(OBJS) $(MLX)
# 				@cc $(MLX) -lmlx -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

# all:			$(NAME) 1337_logo


# clean : 
# 	@make -C minilibx clean
# 	@$(RM) $(OBJS)
# 	echo "\033[31mDELETE .O FILES🗑\033[0m"


# fclean: clean
# 	$(RM) $(MLX)
# 	$(RM) minilibx/library
# 	@$(RM) $(NAME)

# re:				fclean $(NAME)

# .PHONY:			all clean fclean re