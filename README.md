# Pending tasks

- memory study
- Exhaust tests
- cmake and makefile

# 10 rules for developing safety-critical code are:

* Restrict all code to very simple control flow constructs—do not use goto statements, setjmp or longjmp constructs, or direct or indirect recursion.
* Give all loops a fixed upper bound.
* Do not use dynamic memory allocation after initialization.
* No function should be longer than what can be printed on a single sheet of paper in a standard format with one line per statement and one line per declaration.
* The code's assertion density should average to minimally two assertions per function.
* Declare all data objects at the smallest possible level of scope.
* Each calling function must check the return value of nonvoid functions, and each called function must check the validity of all parameters provided by the caller.
* The use of the preprocessor must be limited to the inclusion of header files and simple macro definitions.
* Limit pointer use to a single dereference, and do not use function pointers.
* Compile with all possible warnings active; all warnings should then be addressed before the release of the software.

# General

## strcmp vs strncmp

`strcmp` and `strncmp` are both functions in the C standard library used for comparing strings. However, they have a key difference in how they operate.

### `strcmp`

`int strcmp(const char *s1, const char *s2);`

This function compares the two strings `s1` and `s2`. The comparison is done lexicographically.

- It returns an integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to match, or be greater than `s2`.
- `strcmp` does not have a limit on the number of characters it compares. It will continue until it finds a null terminator (`\0`) in one of the strings. This can lead to buffer overflows if not used carefully with strings that are not null-terminated.

### `strncmp`

`int strncmp(const char *s1, const char *s2, size_t n);`

This function is similar to `strcmp`, but it compares at most `n` characters of `s1` and `s2`.

- It also returns an integer less than, equal to, or greater than zero.
- Because it has a limit on the number of characters to compare, `strncmp` is generally safer to use than `strcmp` as it can prevent buffer overflows when dealing with non-null-terminated strings.

### Summary

- Use `strcmp` when you are sure both strings are null-terminated.
- Use `strncmp` when you are dealing with strings that might not be null-terminated or when you only need to compare a specific number of characters. It is the safer option.

