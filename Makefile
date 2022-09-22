
# **************************************************************************** #
#                               COLORS / DESIGN	                               #
# **************************************************************************** #

GREEN		= \033[32;1m
RED			= \033[31;1m
YELLOW		= \033[33;1m
CYAN		= \033[36;1m
RESET		= \033[0m
WHITE 		= \033[0;m

CLEAR		= \033[2K\r
# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= executable

DIRSRC			= src/

DIROBJ			= objs/

# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC				= c++

CFLAGS 			= -Wall -Wextra -Werror -std=c++98 -g

INCLUDES 		= -I ./includes

LDFLAGS			=


# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRC 			= vector_testeur.cpp

OBJ 			:= $(SRC:.cpp=.o)

SRC				= $(addprefix $(DIRSRC), $(SRC))

DIROBJS			= $(addprefix $(DIROBJ), $(OBJ))

# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #


all: 			$(NAME)

leaks:			all
				valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes



$(DIROBJ)%.o:${DIRSRC}%.cpp
				@mkdir -p $(DIROBJ)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):		$(DIROBJS)
				@printf "  $(YELLOW)Compiling and linking all the files $(END)⌛\n"
				@$(CC) $(INCLUDES)  $(CFLAGS) $(DIROBJS)  $(LDFLAGS) -o $@
				@printf "[$(GREEN)OK$(WHITE)] $(NAME) generated. \n"

test:			$(NAME)
				@mkdir -p test_results
				@$(CC) $(INCLUDES)  $(CFLAGS) $(DIROBJS)  $(LDFLAGS) -o test_results/std
				@$(CC) $(INCLUDES)  $(CFLAGS) $(DIROBJS)  $(LDFLAGS) -D library=0 -o test_results/ft
				@chmod +x test_results/std
				@chmod +x test_results/ft
				@printf "  $(YELLOW)Compiling and linking all the tests $(END)⌛\n"
				@printf "[$(GREEN)OK$(WHITE)] Tests generated. \n"
				@./script.sh

clean:
				@rm -rf $(OBJS)	$(DIROBJ)
				@rm -rf test_results
				@printf "[$(GREEN)cleaned$(WHITE)] .o FILES \n"

fclean:			clean
				@rm -rf $(NAME)
				@rm -rf test_results
				@printf "[$(GREEN)cleaned$(WHITE)] $(NAME) \n\n"

re:				fclean all

.PHONY: 		all clean fclean re

