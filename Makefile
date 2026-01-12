CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = test_alloc

SRC = src/pool_allocator.c tests/test_alloc.c

INC = -Iinclude

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)


