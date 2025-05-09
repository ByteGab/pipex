# pipex

## Description
`pipex` is a Unix-style utility that connects two commands using a pipe. It reads from an input file, executes two commands in sequence (passing the first command’s output as the second’s input), and writes the final result to an output file. It also supports a `here_doc` mode to read inline input until a specified delimiter.

---

## Prerequisites

- Unix-like environment (Linux or macOS)  
- C compiler (e.g., `gcc`)  
- Knowledge of system calls: `pipe()`, `fork()`, `dup2()`, `execve()`, and `wait()`

---

## Main Checklist

1. **Argument Validation**  
   - Ensure exactly five arguments (six when using `here_doc`).  
   - Print an error and exit if the count is incorrect.

2. **File Checks**  
   - Verify the input file exists.  
   - Understand how `>` creates the output file when it doesn't exist.

3. **Pipe Creation**  
   - Call `pipe()` to get two file descriptors: one for reading, one for writing.

4. **Process Management**  
   - `fork()` a child for the first command.  
   - In the parent, wait for the child, then `fork()` again for the second command.

5. **Synchronization**  
   - Parent waits for all children before exiting.

> **Note:** In `here_doc` mode, the second argument is the delimiter, not a command.

---

## Execution Checklist

1. **Locate Binaries**  
   - Parse `PATH` from `envp`.  
   - For each directory, build `dir/command` and test with `access()`.

2. **Prepare Arguments**  
   - Split the command string into an array of arguments (including the command itself).

3. **Execute**  
   - Call `execve(path, argv, envp)` to replace the process image.

---

## Module Overview

### `main`
- Entry point  
- Responsibilities:  
  - Validate arguments  
  - Create pipe  
  - Fork for first command → call `child_process`  
  - Wait, then `fork()` for second command → call `father_process`  
  - Handle errors

### `child_process`
- Handles first command  
- Responsibilities:  
  - Open `infile` for reading  
  - Redirect STDIN from `infile` and STDOUT to pipe write end (`dup2`)  
  - Close unused pipe descriptors  
  - Call `execute_cmd` for the second command

### `father_process`
- Handles second command  
- Responsibilities:  
  - Open `outfile` for writing (create if needed)  
  - Redirect STDIN from pipe read end and STDOUT to `outfile` (`dup2`)  
  - Close unused pipe descriptors  
  - Call `execute_cmd` for the first command

### `execute_cmd`
- Executes a single command  
- Responsibilities:  
  - Split command string into arguments  
  - Call `find_cmd` to get full binary path  
  - On success → `execve`  
  - On failure → free resources and call `ft_perror`

### `find_cmd`
- Searches for binary in `PATH`  
- Responsibilities:  
  - Extract `PATH` from `envp`  
  - Split on `:` into directories  
  - Check each `dir/command` with `access()`  
  - Return full path or `NULL`

### `ft_perror`
- Error handling  
- Responsibilities:  
  - Print error to `stderr`  
  - Exit with failure status

---

## Key Concepts

- **Pipe:** Unidirectional channel between processes. `pipe(fds)` fills `fds[0]` (read) and `fds[1]` (write).  
- **fork():** Creates a child process; returns 0 in child, child PID in parent.  
- **dup2(oldfd, newfd):** Duplicates `oldfd` onto `newfd`, closing `newfd` first if open.  
- **execve(path, argv, envp):** Replaces current process with new program; does not return on success.  
- **wait():** Blocks parent until a child terminates.  
- **envp:** Array of environment variables (`KEY=VALUE`).

---

## Usage

```bash
# Compile
gcc -Wall -Wextra -Werror pipex.c -o pipex

# Standard mode
./pipex infile "cmd1 args" "cmd2 args" outfile

# Here-doc mode
./pipex here_doc DELIMITER "cmd args" outfile
