SRCS =	main.c 		\
		checkmap.c 	\
		checkpos.c	\
		draw.c		\
		drawmap.c	\
		moves.c		\
		checkpath.c	\
		checkwin.c	\
		draweatanim.c

NAME = so_long

BONUS = so_long_bonus

SRCSB =	main_bonus.c 		\
		checkmap_bonus.c 	\
		checkpos_bonus.c	\
		draw_bonus.c		\
		drawmap_bonus.c	\
		moves_bonus.c		\
		checkpath_bonus.c	\
		checkwin_bonus.c	\
		draweatanim_bonus.c

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

bonus: $(OBJSB) so_long_bonus.h
	 cd ./libft && make && cd ..
	 cc $(OBJSB) $(LIBFT) $(GNL) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

clean:
	cd ./libft && make clean && cd ..
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	cd ./libft && make fclean && cd ..
	rm -f $(NAME) $(BONUS) $(LIBFT)
	

re: fclean all

.PHONY : clean fclean re all
