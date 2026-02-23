*This activity has been created as part of the 42 curriculum by ybarakat, sabaraka.*

# Push Swap

## Description

push_swap is a sorting program that sorts a stack of integers using a limited set of operations and the smallest possible number of moves.

The program receives a list of integers as arguments, stores them in stack A, and sorts them in ascending order using stack B as auxiliary storage.
All operations performed are printed to standard output.

This implementation includes an adaptive sorting system that dynamically selects the most efficient algorithm based on the measured disorder of the input.

---

## Instructions

### Compilation

Run the Makefile:

    make

---

### Usage

Basic usage:

    ./push_swap 3 2 1

Using strategy selectors:

    ./push_swap --adaptive 3 2 1
    ./push_swap --simple 3 2 1
    ./push_swap --medium 3 2 1
    ./push_swap --complex 3 2 1

Enable benchmark mode:

    ./push_swap --bench 3 2 1
    ./push_swap --bench --adaptive 3 2 1

Arguments can also be passed as a single string:

    ./push_swap "3 2 1 5 4"

---

### Cleaning

Remove object files and executable:

    make fclean

---

### Recompilation

Recompile everything from scratch:

    make re

---

## Allowed Operations

- sa, sb, ss — swap the first two elements
- pa, pb — push between stacks
- ra, rb, rr — rotate stacks upward
- rra, rrb, rrr — rotate stacks downward

All operations are printed to stdout, exactly as required by the subject.

---

## Flags

--adaptive  
Automatically selects the best sorting strategy

--simple  
Forces simple O(n²) sorting

--medium  
Forces medium O(n√n) chunk-based sorting

--complex  
Forces complex O(n log n) radix sorting

--bench  
Prints benchmark statistics to stderr

---

## Benchmark Mode

When --bench is enabled, statistics are printed to stderr after sorting:

- Disorder percentage
- Strategy used
- Total number of operations
- Count of each operation

Example output:

    [bench] disorder: 23.45%
    [bench] strategy: Adaptive
    [bench] total_ops: 512
    [bench] sa: 10  sb: 0  ss: 0  pa: 250  pb: 250
    [bench] ra: 30  rb: 12  rr: 0  rra: 5  rrb: 3  rrr: 0

---

## Algorithm and Data Structure

### Data Structure

Stacks are implemented using doubly linked lists.
Each node contains:
- value
- index (used for sorting algorithms)
- previous and next pointers

---

### Disorder Metric

The disorder value is a number between 0 and 1 that measures how far the stack is from being sorted.

It is calculated by counting inverted pairs:

    disorder = inverted_pairs / total_pairs

---

### Adaptive Strategy

Based on the disorder value:

- disorder < 0.2  
  Uses Simple Sort (selection-based)

- 0.2 ≤ disorder < 0.5  
  Uses Medium Sort (chunk-based)

- disorder ≥ 0.5  
  Uses Complex Sort (binary radix sort)

This approach minimizes the number of operations by adapting to the input structure.

---

### Sorting Algorithms

Simple Sort (O(n²))
- Best suited for small or nearly sorted inputs
- Repeatedly pushes the minimum element to stack B and restores stack A

Medium Sort (O(n√n))
- Divides indexed values into ranges (chunks)
- Pushes chunks to stack B and rebuilds stack A efficiently

Complex Sort (O(n log n))
- Binary radix sort using indexed values
- Optimized for large input sizes (100–500 numbers)

---

## Error Handling

The program properly handles:
- Duplicate numbers
- Non-numeric input
- Integer overflow / underflow
- Invalid flags

On error, the program prints:

    Error

to stderr and exits cleanly.

---

## Resources

- [`Revising algorithms`](https://www.youtube.com/@MichaelSambol)
- geekforgeeks
- some push swap videos on youtupe to see some ideas

## AI Usage

- Explaining algorithm behavior
- Debugging edge cases
- Reviewing and fixing Norminette issues
- styling README
