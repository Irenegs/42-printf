####################################### BEG ######

NAME        = libftprintf.a

#////////////////#
#   INGREDIENTS  #
#////////////////#

LIB			= ft

SRCS		= ft_printf.c ft_printf_utils.c ft_strlen.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR		= ar
ARFLAGS	= -r -c -s

RM			= rm -f
#MAKEFLAGS	+= --silent  --no-print-directory

#////////////////#
#   RECIPES      #
#////////////////#

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(ARFLAGS) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

#cambiar clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

#////////////////#
#   SPEC         #
#////////////////#

.PHONY: clean fclean re all

####################################### END ######
