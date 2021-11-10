NAME			= libftprintf.a
INCLUDES				=	./

SRCS			=	ft_printf.c	ft_utils.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c
				$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS) ./ft_printf.h
				@ar rcs $(NAME) $(OBJS)
				@echo "All done"

clean:
				$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@echo "All clean"
re:				fclean $(NAME)

norm :
	norminette *.c *.h

.PHONY:			all clean fclean re  norm
