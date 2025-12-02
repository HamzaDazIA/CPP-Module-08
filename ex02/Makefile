SRC = main.cpp 

OBJ = ${SRC:.cpp=.o}

HEADER = MutantStack.hpp

NAME = MutantStack

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

