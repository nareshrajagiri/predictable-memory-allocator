#include <stdio.h>
#include "pool_allocator.h"

int main(void)
{
    memory_pool_t pool;

    if (pool_init(&pool) != 0) {
        printf("Pool initialization failed\n");
        return 1;
    }

    void* p = pool_alloc(&pool);
    printf("Allocated p: %p\n", p);

    pool_free(&pool, p);
    printf("Freed p once\n");

    /* Intentional double free — should assert */
    pool_free(&pool, p);
    printf("ERROR: double free was not detected\n");

    return 0;

    // void* blocks[POOL_BLOCK_COUNT];

    // /* Allocate all blocks */
    // for (size_t i = 0; i < POOL_BLOCK_COUNT; i++) {
    //     blocks[i] = pool_alloc(&pool);
    //     if (blocks[i] == NULL) {
    //         printf("Allocation failed unexpectedly at index %zu\n", i);
    //         return 1;
    //     }
    // }

    // printf("All %d blocks allocated successfully\n", POOL_BLOCK_COUNT);

    // /* Pool should now be exhausted */
    // void* extra = pool_alloc(&pool);
    // if (extra != NULL) {
    //     printf("Error: allocation succeeded despite exhaustion\n");
    //     return 1;
    // }

    // printf("Allocation correctly returned NULL after exhaustion\n");

    // /* Free one block */
    // pool_free(&pool, blocks[0]);
    // printf("Freed one block\n");

    // /* Allocation should succeed again */
    // void* reused = pool_alloc(&pool);
    // if (reused == NULL) {
    //     printf("Error: allocation failed after freeing a block\n");
    //     return 1;
    // }

    // printf("Allocation succeeded after free: %p\n", reused);

    // return 0;
}
