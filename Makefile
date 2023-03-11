SRCS = so_long.c srcs/error.c validation/validation.c \
validation/validation3.c validation/validation2.c  srcs/ft_split.c \
srcs/get_next_line.c srcs/get_next_line_utils.c srcs/ft_strdup.c \
srcs/ft_itoa.c movement/movment.c movement/movemnet2.c srcs/ft_printf.c



OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.
NAME			= so_long


%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

all:		1337_logo	$(NAME) 

$(NAME):	1337_logo	$(OBJS)
			@cc -lmlx -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)
			@echo "\033[92m✅SO_LONG GENERATED YOU CAN STARTED✅\033[0m"
			@echo "🎮 USE ./SO_LONG <MAP FILE NAME> 🎮"
clean:
				@$(RM) $(OBJS) 
				@echo "\033[31m Delete object files🗑\033[31m"
			
fclean:			clean
				@$(RM) $(NAME)
				@echo "\033[31m Delete exucted file🗑\033[31m"

re:				fclean $(NAME)

1337_logo:

	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m███╗░░░███╗███████╗██████╗░"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m████╗░████║██╔════╝██╔══██╗"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m██╔████╔██║█████╗░░██║░░██║"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m██║╚██╔╝██║██╔══╝░░██║░░██║"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m██║░╚═╝░██║███████╗██████╔╝"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m╚═╝░░░░░╚═╝╚══════╝╚═════╝░"
	@echo "\033[92mCREATING .O FILES AND SO_LONG⌛\033[0m"

.PHONY: all fclean clean re 1337_logo
