# Define the compiler and compiler flags
CC = gcc
CFLAGS = -I.

# Function to perform a recursive wildcard search for .c files
rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)$(filter $(subst *,%,$2),$d))

# Find all .c source files recursively
SRC = $(call rwildcard,.,*.c)

# Generate a list of object files from the source files
OBJ = $(SRC:.c=.o)

# Generate a list of executables from the source files
EXEC = $(SRC:.c=)

# Default target to build all executables
all: $(EXEC)

# Rule to link object files to create executables
%: %.o
	$(CC) -o $@ $<

# Rule to compile source files to object files
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean target to remove generated object files and executables
clean:
	rm -f $(OBJ) $(EXEC)
