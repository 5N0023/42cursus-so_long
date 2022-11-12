SRCS =	main.c 		\
		checkmap.c 	\
		checkpos.c	\
		draw.c		\
		drawmap.c	\
		moves.c			

NAME = so_long


#SRCSB = 	

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

 CC_FLAGS = 

%.o : %.c so_long.h
	cc $(CC_FLAGS) -c $<

$(NAME): $(OBJS)
	make -C ./libft/
	cc $(OBJS) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

# bonus: $(OBJS) $(OBJSB)
# 	ar rc $(NAME) $(OBJSB) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all
