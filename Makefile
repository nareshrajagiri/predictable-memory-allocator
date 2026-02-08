CC = gcc
CFLAGS = -Wall -Wextra -g

INC = -Iinclude
ALLOC_SRC = src/pool_allocator.c

TEST_ALLOC = test_alloc
TEST_COMPARE = test_compare_malloc

all: $(TEST_ALLOC) $(TEST_COMPARE)

$(TEST_ALLOC):
	$(CC) $(CFLAGS) $(INC) $(ALLOC_SRC) tests/test_alloc.c -o $(TEST_ALLOC)

$(TEST_COMPARE):
	$(CC) $(CFLAGS) $(INC) $(ALLOC_SRC) tests/test_compare_malloc.c -o $(TEST_COMPARE)

clean:
	rm -f $(TEST_ALLOC) $(TEST_COMPARE)
