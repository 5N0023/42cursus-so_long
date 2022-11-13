SRCS =	main.c 		\
		checkmap.c 	\
		checkpos.c	\
		draw.c		\
		drawmap.c	\
		moves.c		\
		checkpath.c

NAME = so_long


LIBFT = ./libft/libft.a	
GNL = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

 CC_FLAGS = 
all: $(NAME)

%.o : %.c so_long.h
	cc $(CC_FLAGS) -c $<

$(NAME): $(OBJS)
	 cd ./libft && make && cd ..
	 cc $(OBJS) $(LIBFT) $(GNL) -lmlx -framework OpenGL -framework AppKit -o $(NAME)	 

# bonus: $(OBJS) $(OBJSB)
# 	ar rc $(NAME) $(OBJSB) $(OBJS)

clean:
	cd ./libft && make clean && cd ..
	rm -f $(OBJS)

fclean: clean
	cd ./libft && make fclean && cd ..
	rm -f $(NAME) $(LIBFT)
	

re: fclean all

.PHONY : clean fclean re all
