#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <stddef.h>

/* Build-time configuration */
#define POOL_BLOCK_SIZE   64
#define POOL_BLOCK_COUNT  1024

/* Free list node (in-band metadata) */
typedef struct free_block {
    struct free_block* next;
} free_block_t;

/* Memory pool structure */
typedef struct memory_pool {
    void*         pool_start;
    free_block_t* free_list;
} memory_pool_t;

/* Initialize the memory pool */
int pool_init(memory_pool_t* pool);

#endif /* POOL_ALLOCATOR_H */
