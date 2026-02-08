#include <stdio.h>
#include "pool_allocator.h"

int main(void)
{
    memory_pool_t pool;

    if (pool_init(&pool) != 0) {
        printf("Pool initialization failed\n");
        return 1;
    }

    printf("Initial state:\n");
    printf("  current_allocated = %zu\n", pool.current_allocated);
    printf("  total_alloc_calls = %zu\n", pool.total_alloc_calls);
    printf("  high_watermark    = %zu\n", pool.high_watermark);

    void* p1 = pool_alloc(&pool);
    void* p2 = pool_alloc(&pool);

    printf("\nAfter 2 allocations:\n");
    printf("  current_allocated = %zu\n", pool.current_allocated);
    printf("  total_alloc_calls = %zu\n", pool.total_alloc_calls);
    printf("  high_watermark    = %zu\n", pool.high_watermark);

    pool_free(&pool, p1);

    printf("\nAfter freeing 1 block:\n");
    printf("  current_allocated = %zu\n", pool.current_allocated);
    printf("  total_alloc_calls = %zu\n", pool.total_alloc_calls);
    printf("  high_watermark    = %zu\n", pool.high_watermark);

    pool_free(&pool, p2);

    printf("\nAfter freeing all blocks:\n");
    printf("  current_allocated = %zu\n", pool.current_allocated);
    printf("  total_alloc_calls = %zu\n", pool.total_alloc_calls);
    printf("  high_watermark    = %zu\n", pool.high_watermark);

    return 0;
}
