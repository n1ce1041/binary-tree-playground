# Makefile to compile the binary tree traversal program

CC = gcc
CFLAGS = -Wall -g

# Target for the binary_tree executable
TARGET = binary_tree

# Sources
SRCS = binary_tree.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compile the program
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)
