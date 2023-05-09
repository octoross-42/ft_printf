NAME = libftprintf.a

SRCS = 
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all : NAME

clean : 
	rm -rf $(OBJS)

fclean : 
	rm -rf $(OBJS) $(NAME)

re :
	fclean all