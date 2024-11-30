# Push Swap - 42 Project

## 🚀 Project Overview

**Push Swap** is a project at 42 London that challenges you to sort a given stack of numbers using only a set of specific operations. The goal is to sort the numbers in **as few moves as possible**.

### 📝 Project Details
The project involves manipulating two stacks (stack A and stack B) and sorting the elements according to the following rules:

- **Allowed Moves**: You can move the top element from one stack to the other or rotate/reverse rotate the stacks to bring the required element to the top.
- **Optimizations**: The approach aims to minimize the number of moves by leveraging algorithms such as finding the **longest increasing subsequence** and chunking the data.

---

## 💡 Key Concepts & Approach

### 🧑‍💻 Algorithm Overview

1. **Longest Increasing Subsequence (LIS)**: Identify the longest increasing subsequence in the original stack. This helps by leaving already sorted elements in place to minimize unnecessary moves.
2. **Chunking**: Break the stack into chunks before pushing elements to stack B. This enables more efficient sorting back into stack A.
3. **Pre-sorting**: Two pre-sort iterations:
   - Sort chunks with higher numbers on top, middle in the middle, and lowest numbers at the bottom.
   - Reverse this order and compare results to choose the most efficient sorting method.
4. **Final Sort**: Using the most efficient pre-sorted chunks, the final sorting of the numbers is performed.

### 🧑‍🔬 Performance Results

- **3 numbers**: Less than 3 moves.
- **5 numbers**: Usually less than 10, never more than 12 moves.
- **100 numbers**: Usually less than 600 moves, never more than 700.
- **500 numbers**: Usually less than 5000 moves, never more than 5500.

### 🏆 Bonus - Checker Implementation

I also completed the bonus part of the project, which was to create a "checker" program. This required minimal additional work since most of the code for executing moves was already in place. The key modification was refactoring the code and adding a function to accept instructions via standard input.

---

## 🔧 Files

- **`push_swap.c`**: The main source file implementing the sorting algorithm.
- **`push_swap.h`**: The header file containing function prototypes and necessary includes.
- **`Makefile`**: Automates the build process, creating the `push_swap` executable.
- **`checker.c`**: The implementation of the bonus checker program.

---

## 🧑‍🔧 Compilation & Setup

To compile the project, follow these steps:

### 1. Clone the repository
```bash
git clone https://github.com/your-username/push_swap.git
cd push_swap
```

### 2. Compile the project
To compile the project and generate the push_swap executable, run:
```bash
make
```
This will create the push_swap executable.

### 3. Clean up
To remove the object files:
```bash
make clean
```

To remove all compiled files, including the push_swap executable:
```bash
make fclean
```

To recompile everything from scratch:
```bash
make re
```

## 🧪 Example Usage
To use the push_swap program, simply pass a list of integers as arguments:

```bash
./push_swap 5 3 1 4 2
```
This will output the sequence of moves required to sort the numbers in the most efficient way.

## Checker Example Usage
To use the checker program to validate the output of push_swap, you can pass a sequence of moves in the format of commands (sa, pb, ra, etc.):

```bash
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2
```
This will check whether the sequence of moves sorts the numbers correctly.

# 💡 Key Concepts & Challenges
Efficiency: Minimizing the number of moves required to sort the stack is the primary goal.
Memory Management: Ensuring the program handles large inputs within the constraints of the project.
Algorithm Optimization: Implementing optimizations such as chunking and LIS to reduce the number of required operations.

# 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.

# 🤝 Collaboration
Feel free to contribute to this project! Fork it, submit issues, or open a pull request. If you have suggestions or feedback, don’t hesitate to reach out.

Happy coding! 🚀
