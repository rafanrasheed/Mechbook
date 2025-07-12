# Name of the final executable
TARGET = mechbook

# Source files
SRCS = mechbook.c helpers.c motion.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Default target
all: $(TARGET)

# How to build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean up build artifacts
clean:
	rm -f $(TARGET)

# Optional: run the program
run: $(TARGET)
	./$(TARGET)
