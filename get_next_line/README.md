*This activity has been created as part of the 42 curriculum by ybarakat.*

# Get Next Line Project

## Description

This project reads and returns a line from a file descriptor each time the function is called, handling files of any size and buffering input efficiently using a static stash.

The function returns a line ending with \n when present, or the remaining content at end-of-file.
## Instructions

1. **Compilation**
   - you can compile your files with a defined BUFFER_SIZE:
     ```bash
     cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
     ```

2. **Usage**
   - Include the header in your C files:
     ```c
     #include "get_next_line.h"
     ```
   - Example usage:
    ```c
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    ```
## Resources

- [`helpful for understanding file descriptors and read function `](https://youtu.be/8E9siq7apUU?si=wr8bxkv7I4R-kaWb)
- [`how static variables work `](https://en.wikipedia.org/wiki/Static_variable)
- [`What is the heap vs stack`](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)

#### AI Usage:

- Clarifying why reading byte-by-byte is inefficient and why buffered reading is used
- Explaining the behavior of the read() system call and its return values

### Algorithm

In my implementaion i keep a static buffer that stores any data I’ve read but haven’t returned yet.
On each call, I read from the file descriptor in chunks and keep appending the data until I either find a newline or hit the end of the file.
When I have a full line, I copy it into a new string, return it, and update the buffer so the next call continues from where it stopped.
