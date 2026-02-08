# Predictable Memory Management using a Custom User-Space Allocator

## Overview
A **fixed-size, deterministic memory pool allocator** implemented in user space
to study memory allocation behavior in system and embedded-style software.

This project focuses on **predictability, bounded behavior, and correctness**
rather than general-purpose flexibility.

---

## Why this project
General-purpose allocators like `malloc/free` optimize for flexibility and
average-case performance, which can lead to unpredictable behavior in
`performance-critical` or `resource-constrained systems`.

This allocator demonstrates how **fixed memory bounds and simple data structures**
enable deterministic allocation and explicit failure handling.

---

## Key Characteristics
- Fixed-size memory pool (no heap growth after init)
- Constant-time allocation and free
- Deterministic failure on exhaustion
- No external fragmentation by design
- Debug-time misuse detection (double free, invalid pointer)
- Allocation usage observability (current usage, peak usage)

---

## Non-Goals
- Variable-size allocations
- Replacing glibc `malloc`
- Kernel-space memory management
- Thread safety

---

## Repository Structure

```
include/   → public allocator interface
src/       → allocator implementation
tests/     → correctness and comparison tests
docs/      → detailed design notes
logs/      → captured test outputs
```
---

## Build & Run
```bash
make
./test_alloc
./test_compare_malloc
```
---
### Notes

This allocator is not a general-purpose replacement for malloc.
It is intentionally specialized to highlight trade-offs between
flexibility and predictability in system software.


