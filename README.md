# get_next_line  

## Description  
`get_next_line` is a custom implementation of a function that reads a line from a file descriptor (fd) one at a time, handling newlines correctly. The function continuously returns the next line until the end of the file (EOF) is reached. This project is commonly undertaken at 42 to deepen understanding of file I/O, memory management, and static variables in C.  

## Features  
- Reads a file line by line.  
- Works with any file descriptor (e.g., standard input, files, pipes).  
- Handles large files efficiently with a customizable buffer size.  
- Manages memory dynamically to handle lines of any length.  

## Function Prototype  
```c
char *get_next_line(int fd);
```

## How It Works  
1. Reads from `fd` using `read()`, storing data in a buffer.  
2. Uses a static variable to keep track of leftover data between calls.  
3. Extracts a full line and returns it.  
4. Frees memory when the end of the file is reached.  

## Usage  
Compile with:  
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
Run with a file:  
```sh
./gnl file.txt
```

## Notes  
- `BUFFER_SIZE` can be changed at compile-time using `-D BUFFER_SIZE=N`.  
- The function should return `NULL` when reaching EOF or encountering an error.  

## Learning Outcomes  
- Deepened understanding of `read()`, file descriptors, and static variables.  
- Improved memory allocation and string manipulation skills.  
- Gained experience handling edge cases like zero-length files and varying buffer sizes.  

##Author
Written by Huyuan Ai during the 42 Berlin Curriculum
