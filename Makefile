SRC = color.c error.c validation.c srcs/ft_split.c  srcs/get_next_line.c srcs/get_next_line_utils.c
INCLUDE		=	so_long.h
OBG			= 	$(SRC:.c=.o)
NAME 		=	so_long
GFLAGS 		= 	-Wall -Wextra -Werror
CC 			=	 gcc
AR 			=	 ar -rc
RM  	    =    rm -rf


%.o : %.c 
	@$(CC) $(GFLAGS) -c $< -o $@ -I $(INCLUDE)  

$(NAME) : $(OBG)
	@$(AR) $(NAME) $(OBG)

all   : $(NAME) 1337_logo

clean : 
	@$(RM) $(OBG)
	@echo "\033[31mDELETE .O FILES🗑\033[0m"
fclean: clean
	@$(RM) $(NAME)

re    : fclean all

test  : re
	@echo "\033[92m TESTING IN PRORGRESS...✅\033[0m"
	@$(CC) $(GFLAGS) so_long.c $(NAME)
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