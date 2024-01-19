# Grade Analyzer
## Description
Grade Analyzer is a powerful and user-friendly C program designed to process and analyze a list of numerical grades. It provides insights into how each grade compares to the average of the entire list. The program dynamically manages memory to store grades as they are entered, allowing for efficient processing of an arbitrary number of grades.

## Key Features
- **Dynamic Grade Input:** Users can input any number of grades. The program dynamically allocates memory to accommodate the growing list.
- **Memory Management:** Implements dynamic memory allocation and reallocation to efficiently handle varying numbers of grades.
- **Average Calculation:** Computes the average of all entered grades.
- **Grade Comparison:** Compares each individual grade against the calculated average, indicating whether each grade is below, equal to, or above the average.
- **User-Friendly Interface:** Clear prompts guide the user through the process of entering grades and signal the completion of input.
- **Robust Error Handling:** The program is designed to handle erroneous or unexpected inputs gracefully.
- **Memory Usage Reporting:** Provides detailed reports on memory allocation and freeing, enhancing transparency and aiding in debugging.
  
## How to Use
**Compiling the Program:** \
Make sure you have GCC installed on your system. Use the provided Makefile to compile the program:

```bash
make compile
```
**Running the Program:** \
To run the program, use the Makefile's run command:
```bash
make run
```

**Cleaning Up:** \
To clean up the compiled output, use:
```bash
make clean
```

### Entering Grades:
- Enter grades one at a time, followed by pressing Enter.
- Each grade should be a positive number.
- To end the grade input process, enter a negative number.


### Requirements
- GCC Compiler
