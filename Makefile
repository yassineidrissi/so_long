SRCS = so_long.c color.c error.c validation.c srcs/ft_split.c \
 srcs/get_next_line.c srcs/get_next_line_utils.c srcs/ft_strdup.c \
 print.c srcs/ft_itoa.c movment.c

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


OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.

NAME			= so_long

MLX				= minilibx/library/libmlx.a

all:			$(NAME)

$(MLX)			: 
					make -C minilibx

$(NAME):		$(OBJS) $(MLX)
				cc $(MLX) -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) 
				make -C minilibx clean

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

1337_logo:

	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m███╗░░░███╗███████╗██████╗░"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m████╗░████║██╔════╝██╔══██╗"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m██╔████╔██║█████╗░░██║░░██║"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m██║╚██╔╝██║██╔══╝░░██║░░██║"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m██║░╚═╝░██║███████╗██████╔╝"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m╚═╝░░░░░╚═╝╚══════╝╚═════╝░"
	@echo "\033[92mCREATING .O FILES AND LIBFTPRINTF.A✅\033[0m"

.PHONY: all fclean clean test 1337_logo

