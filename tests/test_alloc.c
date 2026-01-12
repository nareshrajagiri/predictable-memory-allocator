#include <stdio.h>
#include "pool_allocator.h"

int main(void)
{
    memory_pool_t pool;

    if (pool_init(&pool) != 0) {
        printf("Pool initialization failed\n");
        return 1;
    }

    void* p1 = pool_alloc(&pool);
    void* p2 = pool_alloc(&pool);

    printf("Allocated block 1: %p\n", p1);
    printf("Allocated block 2: %p\n", p2);
    printf("Free list head:    %p\n", (void*)pool.free_list);

    return 0;
}
