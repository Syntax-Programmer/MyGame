# Compiler
CC = gcc

# Output executable name
OUT = MyGame.out

# Directories
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data
DOCS_DIR = docs

# Source files and object files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/game.c $(SRC_DIR)/sdl_handler.c
OBJS = $(SRCS:.c=.o)

# Compiler flags
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra -std=c99

# SDL2 linking flags (adjust if using a different SDL version)
SDL_FLAGS = $(shell sdl2-config --cflags --libs)

# Rule to build the executable
$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(SDL_FLAGS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
.PHONY: clean
clean:
	rm -f $(SRC_DIR)/*.o $(OUT)
