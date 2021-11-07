NAME_PRINTF = libftprintf.a

#LIB_DIR =  ./libft/
#LIB_NAME =	libft/libft.a
#LIBFT = libft.a

CC		= gcc

HEADER	= ./includes

FLAGS	= -Wall -Wextra -Werror -g

OBJS	= $(SRCS:.c=.o)

DIR		= ./SRC/

SRCS = $(DIR)ft_printf.c

AR		= ar rc

.c.o:
	$(CC) $(FLAGS) -c  -I$(HEADER) $< -o $(<:.c=.o)

all: $(LIBFT) $(NAME_PRINTF)

bonus : $(LIBFT) $(NAME_PRINTF)

$(LIBFT):
		@echo "Compile libft.a"
		@$(MAKE) -C $(LIB_DIR)
		@echo "Compile OK"
$(NAME_PRINTF): $(OBJS)
		@cp libft/libft.a $(NAME_PRINTF)
		@$(AR) $(NAME_PRINTF) $(OBJS)
		ranlib $(NAME_PRINTF)
clean:
	make clean -C $(LIB_DIR)
	rm $(OBJS)
fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME_PRINTF)

re: fclean all



.PHONY: all clean fclean re code bonus