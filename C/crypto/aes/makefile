CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

TARGET = test.o
SRCDIRS = aes modes
INCDIRS = aes modes
OBJDIR = ./

SOURCES := $(wildcard $(addsuffix /*.c, $(SRCDIRS))) test.c
OBJECTS := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SOURCES)))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(addsuffix /%.c, $(SRCDIRS))
	$(CC) $(CFLAGS) -I$(addsuffix /, $(INCDIRS)) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
