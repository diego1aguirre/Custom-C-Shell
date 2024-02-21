# Makefile for compiling shell program

# Compiler and compiler flags
CC = gcc
	CFLAGS = -Wall -Werror -g

# Define the target executable name
TARGET = shell

# Define the source and object files
SRC = shell.c
OBJ = $(SRC:.c=.o)

# Default target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# To create object files from C source files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean target
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: clean