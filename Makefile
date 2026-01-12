CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = test_init

SRC = src/pool_allocator.c tests/test_init.c
INC = -Iinclude

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
