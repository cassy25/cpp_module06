NAME	=	Identify

CC		=	c++ 
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS	=	$(SRCS:.cpp=.o)

%.o:%.cpp
		c++ -Wall -Wextra -Werror -std=c++98 -I./ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all