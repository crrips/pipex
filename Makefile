NAME = pipex

SRC = $(wildcard mandatory/*.c)
SRC_B = $(wildcard bonus/*.c)
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADERS = $(wildcard mandatory/*.h)
HEADERS_B = $(wildcard bonus/*.h)

RED 	= \033[31m
GREEN 	= \033[32m
END 	= \033[0m

all: $(NAME)
$(NAME):$(OBJ)
	@cc $(FLAGS) $(OBJ) -o $@ 
	@echo "$(GREEN):::\t Executable file $(NAME) was compiled! \t:::$(END)"
	
%.o:%.c $(HEADERS)
	@cc $(FLAGS) -c $< -o $@

bonus: 
	@make OBJ="$(OBJ_B)" HEADERS="$(HEADERS_B)" all

clean:
	@rm -f $(OBJ) $(OBJ_B)
	@echo "$(RED):::\t Object files was deleted! \t\t:::$(END)"

fclean:clean
	@rm -f $(NAME)
	@echo "$(RED):::\t Executable file $(NAME) was deleted! \t:::$(END)"

re:	fclean all
	@echo "$(GREEN):::\t Project was reloaded! \t\t\t:::$(END)"

reb: fclean bonus
	@echo "$(GREEN):::\t Project was reloaded! \t\t\t:::$(END)"

.PHONY: all clean fclean re reb bonus