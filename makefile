CC = gcc
CFLAGS = -Wall -g

# Directories for object files and executable
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC = binary_tree.c binary_tree_iterative.c stack.c
OBJ = $(SRC:.c=.o)

# Executables
EXEC = $(BIN_DIR)/binary_tree
EXEC_ITERATIVE = $(BIN_DIR)/binary_tree_iterative

# Create directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
all: $(EXEC) $(EXEC_ITERATIVE)

# Rule to build the recursive binary tree program
$(EXEC): $(OBJ_DIR)/binary_tree.o $(OBJ_DIR)/stack.o
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build the iterative binary tree program
$(EXEC_ITERATIVE): $(OBJ_DIR)/binary_tree_iterative.o $(OBJ_DIR)/stack.o
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files to .o files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean
 