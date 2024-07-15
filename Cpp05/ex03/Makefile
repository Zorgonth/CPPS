NAME = Form

SRC = main.cpp Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp Intern.cpp\

CFLAGS = -Wall -Wextra -Werror -std=c++98 

OBJ = $(SRC:.cpp=.o)

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@rm -rf Shrubbery

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re