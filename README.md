# Pipex

### Description
**Pipex** is a C program that mimics the behavior of shell commands when handling pipes. It takes four arguments, representing two files and two shell commands with their parameters, and behaves exactly like the shell command:
```
< file1 cmd1 | cmd2 > file2
```
This project is designed to give an understanding of how pipes work in Unix-like operating systems.

### Usage
Compile the program using the `Makefile` and run it as follows:
```
./pipex file1 cmd1 cmd2 file2
```
- `file1`: The name of the input file.
- `cmd1`: The first command to be executed with its parameters.
- `cmd2`: The second command to be executed with its parameters.
- `file2`: The name of the output file.

### Example
``` bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
This is equivalent to the shell command:
``` bash
< infile ls -l | wc -l > outfile
```
Another example:
``` bash
$> ./pipex infile "grep a1" "wc -w" outfile
```

Equivalent to:
``` bash
< infile grep a1 | wc -w > outfile
```
