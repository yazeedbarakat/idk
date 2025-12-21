*This project has been created as part of the 42 curriculum by ybarakat.*

# Printf Project

## Description

A custom implementation of the printf function in C. This project reproduces the behavior of the standard printf function, handling various format specifiers including %c, %s, %d, %i, %u, %x, %X, and %p.

## Instructions

1. **Compilation**
   - Run the Makefile:
     ```bash
     make
     ```

2. **Usage**
   - Include the header in your C files:
     ```c
     #include "ft_printf.h"
     ```
   - Link the library during compilation:
     ```bash
     cc main.c libftprintf.a -I. -I../libft -o my_program             # main.c is your file
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

- [`va_start`, `va_arg`, `va_end`, `va_copy` - Microsoft Docs`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170) — Reference for variadic argument macros.
- [`printf` family reference (C Standard Library) - cppreference`](https://en.cppreference.com/w/c/io/fprintf) — Standard `printf`, formatting specifiers, and return values.

#### AI Usage:

- Some ideas on how to shrink the code
- Explaining function behavior
- Reviewing and correcting Norminette
