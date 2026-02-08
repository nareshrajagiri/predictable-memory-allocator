# Predictable Memory Management using a Custom User-Space Allocator

## Overview
This project implements a **simple, predictable, fixed-size memory pool allocator**
in **user space** to study memory allocation behavior in system and embedded-style
software.

The goal is **not** to replace `malloc/free`, but to demonstrate why general-purpose
allocators are often unsuitable for **performance-critical, real-time, or
resource-constrained systems**, where **determinism and bounded behavior** matter
more than flexibility.

---

## Motivation
Standard `malloc/free` implementations are designed for general-purpose workloads.
They optimize for average-case performance and flexibility, which can lead to:

- Unpredictable allocation latency
- External fragmentation
- History-dependent behavior
- Opaque memory usage patterns

In contrast, system and embedded software often requires:
- Bounded allocation time
- Fixed memory limits
- Deterministic failure behavior
- Easy reasoning about worst-case usage

This project explores those trade-offs through a custom allocator.

---

## Design Goals
- Deterministic, constant-time allocation and free
- Fixed-size memory pool with no heap growth after initialization
- Elimination of external fragmentation
- Explicit and testable failure behavior
- Clear invariants and correctness guarantees

---

## Non-Goals
- Variable-size allocations
- Replacing glibc `malloc`
- Kernel-level memory management
- Aggressive performance optimizations
- Thread safety (single-threaded by design)

---

## Allocator Design

### Allocation Model
- Fixed-size blocks
- Singly linked free list
- LIFO allocation and free

### Memory Lifecycle
1. Allocate a contiguous memory pool once during initialization
2. Divide the pool into equal-sized blocks
3. Track free blocks using in-band metadata
4. Perform allocation and free using constant-time pointer operations

### Failure Model
- When the pool is exhausted, allocation returns `NULL`
- No heap growth or OS interaction after initialization
- Recovery is possible after freeing memory

---

## Safety & Debugging Features
- Pointer range and alignment validation
- Debug-only double-free detection using free-list scanning
- Assertions to fail fast on allocator misuse
- No runtime overhead added in release builds

---

## Observability
The allocator tracks:
- Current number of allocated blocks
- Total successful allocation calls
- High-watermark (peak concurrent usage)

These counters allow:
- Memory pool sizing
- Leak detection
- Worst-case usage reasoning

---

## Comparison with malloc/free
This project includes a **behavioral comparison** with `malloc/free`, focusing on:
- Predictability vs flexibility
- Deterministic exhaustion vs OS-managed growth
- Observability vs opaque heap usage

No performance or speed claims are made.

### Key Takeaway

Different allocators exist because different problems exist.
This allocator demonstrates how sacrificing flexibility enables predictable,
bounded, and observable memory behavior, which is often critical in system and
embedded software.

---


## Build & Run

```bash
make
./test_alloc
./test_compare_malloc
```


