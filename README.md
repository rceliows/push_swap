# Push Swap

A sorting algorithm project that sorts integers on a stack using a limited set of operations, implementing an optimized version of the Turk algorithm.

## Description

Push Swap is a 42 school project that challenges you to sort a stack of integers using only two stacks (a and b) and a specific set of operations. The goal is to sort the numbers in ascending order on stack A using the minimum number of operations possible.

## Features

- Efficient sorting algorithm based on the Turk algorithm
- Optimized for different stack sizes
- Special handling for small stacks (2-3 elements)
- Cost analysis to determine the most efficient moves
- Handles edge cases and input validation

## Available Operations

- `sa` - swap the first 2 elements at the top of stack A
- `sb` - swap the first 2 elements at the top of stack B
- `ss` - sa and sb at the same time
- `pa` - push the top element from stack B to stack A
- `pb` - push the top element from stack A to stack B
- `ra` - rotate stack A (shift all elements up by 1)
- `rb` - rotate stack B (shift all elements up by 1)
- `rr` - ra and rb at the same time
- `rra` - reverse rotate stack A (shift all elements down by 1)
- `rrb` - reverse rotate stack B (shift all elements down by 1)
- `rrr` - rra and rrb at the same time

## Installation

Clone the repository and compile the project:

```bash
git clone <repository-url>
cd push_swap
make
```

The Makefile will automatically clone the required libft library if it's not present.

## Usage

Run the program with integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

Or pass numbers as a single string:

```bash
./push_swap "3 2 5 1 4"
```

The program will output the sequence of operations needed to sort the numbers.

### Example

```bash
$ ./push_swap 2 1 3
sa
```

## Algorithm

The sorting algorithm works as follows:

1. **Small stacks (2-3 elements)**: Use hardcoded optimal solutions
2. **Larger stacks**: 
   - Push all but 3 elements to stack B
   - Sort the remaining 3 elements in stack A
   - Calculate the cost for each element in A to be pushed to B
   - Move elements from A to B using the cheapest moves
   - Push all elements back from B to A in their correct position
   - Rotate stack A to have the minimum element on top

### Cost Calculation

The algorithm calculates the cost of moving each element by considering:
- The position of the element in the current stack
- The position of its target in the destination stack
- Whether both moves can be combined (same direction rotation)
- Whether the element is above or below the median

## Project Structure

```
push_swap/
├── Makefile
├── inc/
│   └── main.h              # Header file with structures and function prototypes
├── src/
│   ├── push_swap.c         # Main program entry point
│   ├── stack_init.c        # Stack initialization and preparation functions
│   ├── stack_utils.c       # Stack utility functions (length, find min/max, etc.)
│   ├── errors.c            # Error handling and input validation
│   ├── split.c             # String splitting utility
│   ├── turk_algorithm.c    # Main sorting algorithm implementation
│   ├── sort_three.c        # Optimized sorting for 3 elements
│   ├── init_a_to_b.c       # Node initialization for A to B moves
│   ├── init_b_to_a.c       # Node initialization for B to A moves
│   ├── calc_cost.c         # Cost calculation for optimal moves
│   └── commands/
│       ├── push.c          # Push operations (pa, pb)
│       ├── swap.c          # Swap operations (sa, sb, ss)
│       ├── rotate.c        # Rotate operations (ra, rb, rr)
│       └── rev_rotate.c    # Reverse rotate operations (rra, rrb, rrr)
└── libft/                  # Required library (auto-cloned)
```

## Makefile Commands

- `make` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make fcleanall` - Remove everything including libft
- `make re` - Recompile the project
- `make reall` - Full recompile including libft

## Error Handling

The program handles various error cases:
- Invalid arguments (non-numeric values)
- Numbers outside integer range (INT_MIN to INT_MAX)
- Duplicate numbers
- Invalid syntax (e.g., signs without digits)

All errors output "Error\n" to stderr and exit with status 1.

## Testing

Test the program with various inputs:

```bash
# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1

# Random order
./push_swap 3 7 1 9 2 8 4 6 5

# Edge cases
./push_swap 42
./push_swap "1 2 3"
./push_swap "-2147483648 2147483647"
```

## Performance

The algorithm is optimized to minimize the number of operations:
- 2 numbers: ≤ 1 operation
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: typically < 700 operations
- 500 numbers: typically < 5500 operations

## Dependencies

- libft (automatically cloned from repository)
- Standard C library

## Compilation Flags

The project uses strict compilation flags:
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

## Author

This project is part of the 42 school curriculum.

## License

This project is for educational purposes.
