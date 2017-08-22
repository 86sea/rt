NAME = RTv1

SRC = main.c \
		raytrace.c \
		init.c \
		vector.c \

OBJ = ${SRC:c=o}

LIBFT = ../libft/libft.a

FLAGS = -lmlx -framework Opengl -framework Appkit -Werror -Wextra -Wall

FLAGSLINUX = -L/usr/X11/lib -lmlx -lXext -lX11 -lm -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(FLAGS)

linux: 
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(FLAGSLINUX)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

