include source.mk

BINARY					=	caps

CC					=	g++

RM					=	@rm -vf

CXXFLAGS				=	-W -Wall -Wextra -Werror -I./inc/

DEBUG					?=	no

ifeq					($(DEBUG), yes)
CFLAGS				=	-g -ggdb3 -Wfatal-errors
CXXFLAGS			+=	-g -ggdb3
endif

all:					 $(BINARY)

$(BINARY):				$(OBJ_BINARY)
						$(CC) $(OBJ_BINARY) -o $(BINARY)

clean:
					$(RM) $(OBJ_BINARY)
					$(RM) $(TMP_FILE)

fclean:					clean
					$(RM) $(BINARY)
