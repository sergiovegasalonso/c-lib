# Rules

0. Don't write code, only suggestions.
1. Use clear and descriptive names for variables, functions, and structures.
2. Follow consistent indentation and formatting styles throughout the codebase.
3. Use correctly `strcmp` and `strncmp` based on the context of string comparison to ensure safety and correctness.
4. Use correctly `malloc` and `free` to manage dynamic memory allocation and deallocation, ensuring no memory leaks or dangling pointers occur.
5. Include comments and documentation to explain complex logic and decisions in the code.
6. Use correctly `const` to indicate immutability and prevent unintended modifications to variables and data structures.
7. Use correctly `static` to limit the scope of functions and variables to the file they are declared in, reducing namespace pollution and potential naming conflicts.
8. Use correctly `perror` and `fprintf(stderr, ...)` for error handling and reporting, providing clear and informative messages to aid in debugging. `perror` is typically used for system call errors, while `fprintf(stderr, ...)` can be used for custom error messages. 