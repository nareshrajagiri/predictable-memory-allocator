# Commit 6: Allocation Counters and Observability

```
Added allocation counters to observe current usage and peak demand without changing allocator behavior or determinism.
```

## Goal
Add lightweight observability to the allocator without changing allocation
behavior or impacting determinism.

## Design Decisions
- Added counters to memory_pool_t for pool-local state
- Tracked current allocations, total allocation calls, and high watermark
- Updated counters only on successful allocation and valid free

## Invariants Validated
- current_allocated accurately reflects live allocations
- high_watermark captures maximum concurrent usage
- Counters do not affect allocator logic or performance characteristics

## Why This Matters
Observability allows system developers to size memory pools correctly,
detect leaks, and reason about allocator usage without relying on profiling tools.
