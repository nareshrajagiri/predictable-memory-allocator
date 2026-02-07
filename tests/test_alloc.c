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

    printf("Allocated p1: %p\n", p1);
    printf("Allocated p2: %p\n", p2);

    pool_free(&pool, p1);
    printf("Freed p1\n");

    void* p3 = pool_alloc(&pool);
    printf("Allocated p3: %p\n", p3);

    return 0;
}
