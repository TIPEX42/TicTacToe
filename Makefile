PROJECT_DIR	:=		$(CURDIR)

EXE			:=		Tictactoe
NAME		:=		$(PROJECT_DIR)/$(EXE)

INCLUDES	:=		-I$(PROJECT_DIR)/Dependencies/raylib/include
INCLUDES	+=		-I$(PROJECT_DIR)/Dependencies/raylib/sources/raylib/src
LIBS		:=		-L$(PROJECT_DIR)/Dependencies/raylib/sources/raylib/src -lraylib

CC			:=		g++

CFLAGS		:=		-Wall -Wextra -O2 -std=c++17 -MD
CFLAGS		+=		$(INCLUDES)

LDFLAGS		:=		$(LIBS)

RM			:=		rm -f

ifeq ($(OS), Windows_NT)
	RM := cmd \/C del
	LDFLAGS += -lopengl32 -lgdi32 -lwinmm -mwindows
else
	UNAME := $(shell uname)
	ifeq ($(UNAME), Linux)
		LDFLAGS += -l GL -l m -l pthread -l dl -l rt -l X11
	endif
	ifeq ($(UNAME), Darwin)
		LDFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
	endif
endif

export CFLAGS
export LDFLAGS
export NAME
export CC
export PROJECT_DIR
export RM

all:
	@$(MAKE) -C Dependencies
	@$(MAKE) -C src -r -R --warn-undefined-variables

run:	all
	./$(EXE)

clean:
	@$(MAKE) -C Dependencies clean
	@$(MAKE) -C src clean

fclean:
	@$(MAKE) -C Dependencies fclean
	@$(MAKE) -C src fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re