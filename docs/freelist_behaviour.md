
# Commit #1

- Fixed-size memory pool initialization

- Correct free list construction

- Verified pool boundaries and invariants



# Commit #2

- Constant-time pool_alloc()

- Correct pointer arithmetic

- Deterministic allocation behavior

- Verified block spacing and free list movement


## Initial free list:

```
Block0 → Block1 → Block2 → ...

After first alloc:
Block1 → Block2 → ...

After second alloc:
Block2 → Block3 → ...  

```
