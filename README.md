*This activity has been created as part of the 42 curriculum by ybarakat.*

# Libft Project

## Description
Libft is a foundational C library project from the 42 curriculum. The goal of this project is to recreate a set of standard C library functions, along with several additional utility functions, to better understand memory management, string manipulation, and linked lists in C.

This library serves as a personal toolkit for future 42 projects, allowing reuse of well-tested functions. Functions include basic string and memory operations, character checks, conversions, as well as linked list handling functions.

## Instructions

1. **Compilation**  
   - Run the Makefile:  
     ```bash
     make
     ```
   -  This builds the static library that you can link to your projects.

2. **Usage**  
   - Include the library header in your C files:
     ```c
     #include "libft.h"
     ```
   - Link the library during compilation:
     ```bash
     cc main.c libft.a -o my_program             # main.c is your file
     ```

3. **Cleaning**  
   - Remove object files and the library:
     ```bash
     make fclean
     ```

4. **Recompilation**  
   - Recompile the library from scratch:
     ```bash
     make re
     ```

## Resources

- [C Standard Library Documentation](https://man7.org/linux/man-pages/man3/)
- [GNU C Library Reference](https://www.gnu.org/software/libc/manual/)
- [Learn C - Linked Lists](https://www.learn-c.org/en/Linked_lists)
- [Makefile Tutorial](https://makefiletutorial.com/)

#### AI Usage:

- Explaining function behavior
- Reviewing and correcting Norminette
