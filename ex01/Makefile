SRC = main.cpp Span.cpp

OBJ = ${SRC:.cpp=.o}

HEADER = Span.hpp

NAME = Span

CC = c++

FLAG = -Wall -Wextra -Werror -std=c++98


%.o : %.cpp
	${CC} ${FLAG} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAG} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

