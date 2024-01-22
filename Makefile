EXECUTABLE_NAME = bsq

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -r $(EXECUTABLE_NAME)

re: fclean
	make

.PHONY: all clean fclean re