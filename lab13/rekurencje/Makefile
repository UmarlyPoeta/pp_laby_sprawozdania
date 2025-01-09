# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = program
SRC = potega.c

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET) 4 5
