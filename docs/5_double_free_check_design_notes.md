# Commit 5: Debug-only Double-Free Detection

```
I added debug-only double-free detection by scanning the free list and asserting on misuse. This prevents silent allocator corruption during development without impacting release performance.
```

## Goal
Detect double-free bugs during development without adding runtime overhead
to release builds.

## Design Decisions
- Implemented free list scanning inside pool_free()
- Enabled detection only in debug builds using NDEBUG guard
- Used assertions to fail fast on allocator misuse

## Invariants Validated
- A block cannot appear twice in the free list (debug)
- Free list corruption is prevented during development
- Allocator behavior is unchanged in release builds

## Why This Matters
Double free is a severe logic error that can silently corrupt allocators.
Catching it early in debug builds prevents hard-to-diagnose failures later.
