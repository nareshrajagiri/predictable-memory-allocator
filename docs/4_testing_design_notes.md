# Commit 4: Pool Exhaustion Behavior and Correctness Tests

```
I explicitly tested allocator exhaustion and verified deterministic failure and recovery without modifying allocator logic.
```

## Goal
Validate deterministic behavior when the memory pool is fully exhausted and
verify allocator recovery after freeing memory.

## Design Decisions
- Did not modify allocator logic
- Focused entirely on correctness testing
- Explicitly tested failure and recovery paths

## Invariants Validated
- Allocation fails deterministically when pool is exhausted
- No memory corruption occurs during exhaustion
- Freeing a block after exhaustion restores allocation capability
- Free list remains consistent across exhaustion boundary

## Why This Matters
In system and embedded software, memory exhaustion must be handled predictably.
This commit proves that allocator failure behavior is well-defined and safe.
