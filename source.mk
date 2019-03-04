SRC_BINARY_DIR	=	./src/

SRC_BINARY		=	$(SRC_BINARY_DIR)main.cpp				\
				$(SRC_BINARY_DIR)date.cpp				\
				$(SRC_BINARY_DIR)children.cpp				\
				$(SRC_BINARY_DIR)account.cpp

OBJ_BINARY		=	$(SRC_BINARY:.cpp=.o)

TMP_FILE		=	$(SRC_BINARY:.cpp=.cpp~)
