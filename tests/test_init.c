#include <stdio.h>
#include "pool_allocator.h"

int main(void)
{
    memory_pool_t pool;

    if (pool_init(&pool) != 0) {
        printf("Pool initialization failed\n");
        return 1;
    }

    printf("Pool initialized successfully\n");
    printf("Pool start address: %p\n", pool.pool_start);
    printf("Free list head:     %p\n", (void*)pool.free_list);

    return 0;
}
