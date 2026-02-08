#include <stdio.h>
#include <stdlib.h>
#include "pool_allocator.h"

/*
 * This test compares behavioral aspects of malloc/free
 * with the custom pool allocator.
 *
 * This is NOT a benchmark.
 * We only observe behavior and failure modes.
 */

int main(void)
{
    const size_t N = POOL_BLOCK_COUNT;

    printf("=== malloc/free behavior ===\n");

    void* malloc_blocks[N];
    size_t i;

    for (i = 0; i < N; i++) {
        malloc_blocks[i] = malloc(POOL_BLOCK_SIZE);
        if (malloc_blocks[i] == NULL) {
            printf("malloc failed at iteration %zu\n", i);
            break;
        }
    }

    printf("malloc allocated %zu blocks\n", i);

    for (size_t j = 0; j < i; j++) {
        free(malloc_blocks[j]);
    }

    printf("malloc/free cycle completed\n\n");

    printf("=== pool allocator behavior ===\n");

    memory_pool_t pool;
    if (pool_init(&pool) != 0) {
        printf("Pool initialization failed\n");
        return 1;
    }

    void* pool_blocks[N];

    for (i = 0; i < N; i++) {
        pool_blocks[i] = pool_alloc(&pool);
        if (pool_blocks[i] == NULL) {
            printf("pool_alloc failed at iteration %zu\n", i);
            break;
        }
    }

    printf("pool_alloc allocated %zu blocks\n", i);

    void* extra = pool_alloc(&pool);
    if (extra == NULL) {
        printf("pool_alloc returned NULL after exhaustion (expected)\n");
    } else {
        printf("ERROR: pool_alloc succeeded after exhaustion\n");
    }

    for (size_t j = 0; j < i; j++) {
        pool_free(&pool, pool_blocks[j]);
    }

    printf("pool_alloc/free cycle completed\n");

    return 0;
}
