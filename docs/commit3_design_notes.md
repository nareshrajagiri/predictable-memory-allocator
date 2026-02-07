# Commit 3: pool_free()

```
Freeing is where most allocator bugs occur, so I added strict pointer range and alignment checks in debug builds and validated reuse behavior before moving forward.
```

## Goal
Introduce safe block deallocation while preserving free list integrity.

## Design Decisions
- Used LIFO free list push for O(1) behavior
- Added debug-only pointer range and alignment checks
- Chose assertions over silent failure to catch bugs early

## Invariants Preserved
- Freed blocks re-enter free list exactly once
- Allocation after free reuses the same block
- Free list structure remains valid

## Non-goals
- Double-free detection in release builds
- Thread safety
- Runtime error recovery
