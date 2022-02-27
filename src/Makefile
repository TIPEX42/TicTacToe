SRCS		:=		main.cpp Game.cpp Cell.cpp

INC			:=		$(PROJECT_DIR)/Dependencies/raylib/include

OBJDIR		:=		objs/
OBJS		:=		$(addprefix $(OBJDIR), $(SRCS:.cpp=.o))

DEPENDS		:=		$(addprefix $(OBJDIR), $(SRCS:.cpp=.d))

all:			$(NAME)

$(NAME):		$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJDIR)%.o:	%.cpp
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiling $<..."

clean:
			@$(RM) $(OBJS) $(DEPENDS)

fclean:			clean

re:	fclean all

.PHONY: all clean fclean re

-include: DEPENDS