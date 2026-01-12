# Predictable Memory Management using a Custom User-Space Allocator

This project implements a simple, fixed-size memory pool allocator in user space
to study deterministic memory allocation behavior in system and embedded-style
software.

## Design goals
- Predictable, constant-time allocation behavior
- Fixed-size memory pool
- No heap growth after initialization
