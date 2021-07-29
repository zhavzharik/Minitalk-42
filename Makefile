SERVER = server

CLIENT = client

SRC_SER = 	server.c		\
			ft_str.c		\
			ft_puterror.c

SRC_CL = 	client.c		\
			ft_str.c		\
			ft_puterror.c	\
			ft_atoi.c


OBJ_SER = $(SRC_SER:.c=.o)

OBJ_CL = $(SRC_CL:.c=.o)

CC = gcc

REM = rm -f

INCL = minitalk.h

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

%.o : %.c $(INCL) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(SERVER): $(OBJ_SER)
	$(CC) $(FLAGS) $(OBJ_SER) -o $(SERVER)

$(CLIENT): $(OBJ_CL)
	$(CC) $(FLAGS) $(OBJ_CL) -o $(CLIENT)

clean :
	$(REM) $(OBJ_SER) $(OBJ_CL)

fclean : clean
	$(REM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re
