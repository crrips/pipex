# Pipex

This repository contains the implementation of the Pipex project, which is part of the curriculum at 42 School. The Pipex project focuses on the practical usage of file descriptors and process management in a Unix-like environment.

## Project Description

Pipex is a program that simulates the behavior of the shell's pipe operator (`|`). It takes four arguments:

1. Input file: the initial file to be used as input.
2. Command 1: the first command to be executed.
3. Command 2: the second command to be executed.
4. Output file: the file where the final output will be written.

The program will execute the two commands concurrently, with the output of the first command being used as the input for the second command. The final output will be redirected to the specified output file.

## Usage

To use this program, follow these steps:

1. Clone the repository or download the relevant files.
2. Compile the code using the provided Makefile.
3. Run the executable, providing the four required arguments.

Example usage:
```bash
./pipex infile "ls -l" "grep pipex" outfile
```

This example runs `ls -l` on the input file and then pipes the output to `grep pipex`, with the final output being written to `outfile`.

## Code Structure

The code is structured to handle the following main tasks:

1. Parsing the input arguments and setting up the initial file descriptors.
2. Creating child processes to execute the specified commands.
3. Managing inter-process communication using pipes.
4. Redirecting input and output appropriately.

The main program is contained in the `pipex.c` file, and relevant functions are organized in separate C files.

## Documentation

For more detailed information about the project, including its requirements and specifics, please refer to the official project documentation and subject provided by 42 School.
