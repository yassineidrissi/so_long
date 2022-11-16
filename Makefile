SRC = so_long.c color.c error.c validation.c srcs/ft_split.c  srcs/get_next_line.c srcs/get_next_line_utils.c srcs/ft_strdup.c\
			# init.c\
			print.c\
			error.c\
			color.c\
			movment.c\
			path.c\
			so_long.c\
			ft_itoa.c\
			term.c

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

.PHONY:			all clean fclean re

# INCLUDE		=	so_long.h
# OBG			= 	$(SRC:.c=.o)
# NAME 		=	so_long
# GFLAGS 		= 	-Wall -Wextra -Werror
# CC 			=	 gcc
# AR 			=	 ar -rc
# RM  	    =    rm -rf
# MLX			=    minilibx.a


# # %.o : %.c 
# # 	$(CC) -g $(GFLAGS) -framework OpenGL -framework AppKit $< -o $@ -I $(INCLUDE)  

# # $(NAME) : $(MLX) $(OBG)
# # 	$(AR) $(NAME) $(MLX) $(OBG)

# all:			$(NAME)

# $(MLX)			: 
# 					make -C minilibx

# $(NAME):		$(OBJS) $(MLX)
# 				cc $(MLX) -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

# clean : 
# 	MAKE -C minilibx clean
# 	$(RM) $(OBG)
# 	@echo "\033[31mDELETE .O FILES🗑\033[0m"
# fclean: clean
# 	$(RM) $(NAME) $(MLX)

# re    : fclean all

# test  : re
# 	@echo "\033[92m TESTING IN PRORGRESS...✅\033[0m"
# 	@$(CC) -g so_long.c $(NAME)
# 	# @./a.out "test.bar" || cat -e

# 1337_logo:

# 	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m███╗░░░███╗███████╗██████╗░"
# 	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m████╗░████║██╔════╝██╔══██╗"
# 	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m██╔████╔██║█████╗░░██║░░██║"
# 	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m██║╚██╔╝██║██╔══╝░░██║░░██║"
# 	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m██║░╚═╝░██║███████╗██████╔╝"
# 	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m╚═╝░░░░░╚═╝╚══════╝╚═════╝░"
# 	@echo "\033[92mCREATING .O FILES AND LIBFTPRINTF.A✅\033[0m"

# .PHONY: all fclean clean test 1337_logo