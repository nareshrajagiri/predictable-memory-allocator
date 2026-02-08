# Commit 2: pool_alloc()

## Goal
Introduce constant-time allocation from a fixed-size memory pool.

## Design Decisions
- Used a singly linked free list
- Chose LIFO allocation to improve cache locality
- Avoided traversal to guarantee O(1) behavior

## Invariants Preserved
- Each allocated block is removed from free list
- No block can be allocated twice
- Allocation fails deterministically when pool is exhausted

## Non-goals
- Freeing memory
- Thread safety
- Fragmentation handling (not needed due to fixed-size blocks)

## Validation
- Verified block spacing equals POOL_BLOCK_SIZE
- Confirmed free list head moves forward after each allocation
