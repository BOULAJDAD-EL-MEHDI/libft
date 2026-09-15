*This project has been created as part of the 42 curriculum by eboulajd.*

# Libft

A static C library implementing 34 character, memory, string, conversion, and file-descriptor utilities.

## Overview

Libft recreates commonly used C library functions and adds string-processing helpers for reuse in other C projects. Its main challenge is implementing familiar interfaces directly: copying bytes safely, respecting buffer boundaries, and managing dynamically allocated results.

The project uses C, Make, and `ar`, with one source file per public function and a shared header. Building produces `libft.a`, which links into a caller's program.

## Key Concepts

| Concept | Application in this project |
| --- | --- |
| Pointers and byte-level memory | Memory routines operate through `unsigned char` pointers; comparisons preserve unsigned byte values. |
| Buffer boundaries | `ft_strlcpy`, `ft_strlcat`, and `ft_strnstr` implement size-limited operations with explicit termination and return-value rules. |
| Memory ownership | Allocating helpers return caller-owned storage; `ft_split` frees partially built results when an allocation fails. |
| Parsing and integer arithmetic | `ft_atoi` reads whitespace, sign, and decimal digits; `ft_itoa` constructs a decimal string, including negative values. |
| Function pointers | `ft_strmapi` creates a transformed string; `ft_striteri` applies a callback in place. |
| Recursion and file descriptors | `ft_putnbr_fd` recursively emits decimal digits; output helpers write to a supplied descriptor. |
| Static linking | The Makefile compiles separate objects and archives them behind the interface in `libft.h`. |

## Architecture

```text
ft_*.c  ──compile──>  ft_*.o  ──ar──>  libft.a
                                         │
caller.c + libft.h  ──────────link─────────┘  ──> executable
```

| Function family | Public functions (`ft_` prefix) |
| --- | --- |
| Characters | `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower` |
| Memory | `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc` |
| String primitives | `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup` |
| String construction | `substr`, `strjoin`, `strtrim`, `split` |
| Conversion | `atoi`, `itoa` |
| Callbacks | `strmapi`, `striteri` |
| Descriptor output | `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd` |

## How It Works

The caller includes `libft.h` and invokes the functions it needs. Most routines scan their input with simple loops. For example, `ft_split` first counts words, allocates a pointer array, then allocates and copies each word. Repeated delimiters are skipped, and a final `NULL` marks the end of the array. If any word allocation fails, previously allocated words and the array are freed.

`ft_memmove` chooses forward or backward copying based on address order so overlapping regions retain their original contents. `ft_strtrim` finds the first and last characters outside a supplied set and allocates the resulting substring.

## Technical Decisions

- **Explicit ownership:** free results from `ft_calloc`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_itoa`, and `ft_strmapi`. For `ft_split`, free each word, then the array. Check allocating functions for `NULL` before use.
- **Small public interface:** helper functions remain `static` inside their source files; `libft.h` declares the 34 public functions.
- **Direct implementations:** character checks use ASCII ranges, output uses `write`, and string routines use loops and other Libft functions.
- **Size-aware allocation:** string indexes use `size_t`; allocation arithmetic is checked when joining strings, allocating split arrays, or multiplying `ft_calloc` dimensions.

### API boundaries

Supply valid pointers, appropriately sized buffers, and valid callbacks. Null-input handling is specific to each function. `ft_memcpy` requires non-overlapping regions; use `ft_memmove` for overlap. Search results point into the original input and must not be freed separately.

Character helpers use ASCII rules. Keep `ft_atoi` inputs within the `int` range when a reliable numeric result is required; it has no error-reporting interface. The `void` output helpers do not report `write` errors or close the caller's descriptor.

## Challenges

- Preserving data when memory regions overlap.
- Handling empty strings, truncation, terminators, and delimiter-only input.
- Cleaning up a partially allocated array of strings.
- Detecting arithmetic overflow before it causes invalid allocation sizes or signed overflow.

## What I Learned

- Translating library contracts into pointer operations and loop boundaries.
- Separating borrowed input from owned heap allocations.
- Building and linking a reusable C archive with strict compiler warnings.
- Testing failure paths alongside normal results using allocation injection and memory-analysis tools.

## Build

Requirements: a C compiler, Make, `ar`, and a Unix-like environment providing `write`.

```sh
make          # Build libft.a with -Wall -Wextra -Werror
make clean    # Remove object files; keep the library
make fclean   # Remove objects and the library
make re       # Clean and rebuild
```

## Usage

Save this as `main.c` in the repository root:

```c
#include "libft.h"

int main(void)
{
    char    **words;
    size_t  i;

    words = ft_split("C:memory:strings", ':');
    if (!words)
        return (1);
    i = 0;
    while (words[i])
    {
        ft_putendl_fd(words[i], 1);
        free(words[i]);
        i++;
    }
    free(words);
    return (0);
}
```

Build and run:

```sh
make
cc -Wall -Wextra -Werror -I. main.c libft.a -o /tmp/libft-example
/tmp/libft-example
```

### Example Output

```text
C
memory
strings
```

## Project Structure

```text
libft/
├── ft_*.c       # One implementation per public function
├── libft.h      # Public declarations
├── Makefile     # Build, clean, rebuild, and test targets
├── tests/       # C assertions, allocation-failure tests, and shell runner
├── .gitignore   # Build artifacts
└── README.md
```

## Testing

```sh
make re
make test
SANITIZE=1 sh tests/run.sh
VALGRIND=1 sh tests/run.sh
python3 -m norminette
```

The six test executables exercise all 34 functions: libc comparisons where applicable, both overlap directions, bounded searches, empty and truncated strings, split cleanup, allocation failures, callback indexes, integer limits, and output captured through pipes. Numeric tests round-trip every integer from -10,000 through 10,000. Memory tests include a 1 MiB buffer.

The test runner requires a linker supporting GNU `--wrap=malloc` for allocation-failure injection. Sanitizer mode rebuilds the library in a temporary directory with AddressSanitizer and UndefinedBehaviorSanitizer. Valgrind and Norminette are optional development tools; test binaries are removed on exit.

Verified on 64-bit Linux with GCC 15.2.0, Valgrind 3.27.1, and Norminette 3.3.60: all six executables passed normally and with sanitizers; Valgrind reported zero memory errors and no outstanding heap allocations in these runs. Norminette passed library and test sources, with an informational notice for the test-only allocation counter. Invalid-descriptor tests intentionally produce Valgrind warnings. Parallel rebuilds and a subsequent no-op `make` were also checked.

These checks do not establish exhaustive coverage or portability to every C platform. A 32-bit build was not verified.

## Resources

- [Linux man-pages: allocation and ownership](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [POSIX `memmove` semantics](https://linuxman7.org/linux/man-pages/man3/memmove.3p.html)
- [GNU Make: archive updates](https://www.gnu.org/software/make/manual/html_node/Archive-Update.html)
