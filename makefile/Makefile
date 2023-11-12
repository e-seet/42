# Variables
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCDIR := src
OBJDIR := obj
BINDIR := bin
SRCFILES := $(wildcard $(SRCDIR)/*.c)
OBJFILES := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCFILES))
TARGET := $(BINDIR)/myprogram

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJFILES)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJFILES) -o $@

# Compiling
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJFILES)

# Full clean (including the executable)
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
