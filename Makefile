
SRCS = so_long.c color.c error.c validation.c srcs/ft_split.c \
 srcs/get_next_line.c srcs/get_next_line_utils.c srcs/ft_strdup.c \
 print.c srcs/ft_itoa.c movment1.c
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -rf
CFLAGS			= -g -Wall -Wextra -Werror -I.

NAME			= so_long

MLX				= minilibx/library/libmlx.a

$(MLX)			: 
					make -C minilibx

$(NAME):		$(OBJS) $(MLX)
				@cc $(MLX) -lmlx -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

all:			$(NAME) 1337_logo


clean : 
	@make -C minilibx clean
	@$(RM) $(OBJS)
	@echo "\033[31mDELETE .O FILES🗑\033[0m"


fclean: clean
	$(RM) $(MLX)
	$(RM) minilibx/library
	@$(RM) $(NAME)

re    : fclean all

test  : re
	@echo "\033[92m TESTING IN PRORGRESS...✅\033[0m"
	@$(CC) -g so_long.c $(NAME)
	# @./a.out "test.bar" || cat -e

1337_logo:

	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m███╗░░░███╗███████╗██████╗░"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m████╗░████║██╔════╝██╔══██╗"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m██╔████╔██║█████╗░░██║░░██║"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m██║╚██╔╝██║██╔══╝░░██║░░██║"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m██║░╚═╝░██║███████╗██████╔╝"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m╚═╝░░░░░╚═╝╚══════╝╚═════╝░"
	@echo "\033[92mCREATING .O FILES AND LIBFTPRINTF.A✅\033[0m"

.PHONY: all fclean clean test 1337_logo
# INCLUDE		=	so_long.h
# OBG			= 	$(SRC:.c=.o)
# NAME 		=	so_long
# GFLAGS 		= 	-Wall -Wextra -Werror
# CC 			=	 gcc
# AR 			=	 ar -rc
# RM  	    =    rm -rf
# MLX         =	minilibx/library/libmlx.a
# %.o : %.c 
# 	@$(CC) -g $(GFLAGS) -c $< -o $@ -I $(INCLUDE)  

# $(MLX) : 
# 		make -C minilibx


# $(NAME) : $(OBG) $(MLX)
# 	@$(AR) $(MLX) $(NAME) $(OBG)

# all   : $(NAME) 1337_logo