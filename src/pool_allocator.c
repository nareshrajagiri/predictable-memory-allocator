#include "pool_allocator.h"

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

int pool_init(memory_pool_t* pool)
{
    assert(pool != NULL);

    size_t total_size = POOL_BLOCK_SIZE * POOL_BLOCK_COUNT;

    /* Allocate raw memory once */
    pool->pool_start = malloc(total_size);
    if (pool->pool_start == NULL) {
        return -1;
    }

    /* Build the free list */
    uint8_t* base = (uint8_t*)pool->pool_start;

    pool->free_list = (free_block_t*)base;

    for (size_t i = 0; i < POOL_BLOCK_COUNT - 1; i++) {
        free_block_t* current =
            (free_block_t*)(base + i * POOL_BLOCK_SIZE);
        free_block_t* next =
            (free_block_t*)(base + (i + 1) * POOL_BLOCK_SIZE);

        current->next = next;
    }

    /* Last block terminates the list */
    free_block_t* last =
        (free_block_t*)(base + (POOL_BLOCK_COUNT - 1) * POOL_BLOCK_SIZE);
    last->next = NULL;

    return 0;
}
