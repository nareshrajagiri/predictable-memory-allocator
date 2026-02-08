# Commit 7: Comparison with malloc/free
```
Compared my allocator with malloc not to claim better performance, but to highlight the trade-off between generality and predictability. malloc optimizes for flexibility, while my allocator provides bounded, deterministic behavior.
```

## Goal
Compare behavioral guarantees of a general-purpose allocator (malloc/free)
with a fixed-size pool allocator, without making performance claims.

## Comparison Dimensions
- Allocation bounds
- Failure behavior
- Predictability
- Observability

## Observations
- malloc is optimized for flexibility and average-case performance
- malloc allocation success depends on OS and heap state
- pool allocator enforces strict memory bounds
- pool allocator provides deterministic failure on exhaustion

## Key Takeaway
The pool allocator is not a replacement for malloc. It is a specialized
allocator designed for predictable behavior in constrained or system-level
contexts.
