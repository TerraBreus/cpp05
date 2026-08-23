NAME = Bureaucrats
COMP = c++
FLAGS = -Wall -Werror -Wextra

SRC := \
	   Bureaucrat.cpp \
	   main.cpp

SRCDIR := src/
OBJDIR := obj/

OBJ := $(addprefix $(OBJDIR), $(SRC:%.cpp=%.o))

all : $(NAME)

debug : FLAGS += -g -DDEBUG
debug : $(NAME)

$(NAME) : $(OBJ)
	$(COMP) $(FLAGS) $(OBJ) -o $@

$(OBJDIR)%.o : $(SRCDIR)%.cpp 
	@mkdir -p $(OBJDIR)
	$(COMP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all
