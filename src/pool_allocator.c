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

void* pool_alloc(memory_pool_t* pool)
{
    assert(pool != NULL);

    /* If no free blocks remain */
    if (pool->free_list == NULL) {
        return NULL;
    }

    /* Take the first free block */
    free_block_t* block = pool->free_list;

    /* Advance free list head */
    pool->free_list = block->next;

    /* Return block to caller */
    return (void*)block;
}

void pool_free(memory_pool_t* pool ,void* ptr)
{
    assert(pool != NULL);
    assert(ptr != NULL);
    uint8_t* pool_start = (uint8_t*)pool->pool_start;
    uint8_t* pool_end = pool_start + (POOL_BLOCK_SIZE * POOL_BLOCK_COUNT);

    uint8_t* p = (uint8_t*)ptr;

    /* Debug-time pointer validation */
    assert(p >= pool_start && p < pool_end);
    assert(((uintptr_t)(p - pool_start) % POOL_BLOCK_SIZE) == 0);

      /* Push block back to free list */
    free_block_t* block = (free_block_t*)ptr;
    block->next = pool->free_list;
    pool->free_list = block;
}


