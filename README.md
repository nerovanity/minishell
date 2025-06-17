# minishell

A simple Unix-like shell implemented in C, as part of the 42 school curriculum. This project aims to reproduce a minimal shell with job control, piping, redirections, environment variable management, and various built-in commands, while adhering to strict coding and design requirements.

---

## Features

- **Prompt**: Displays a prompt when waiting for user input.
- **Command History**: Maintains a working command history using `readline`.
- **Command Execution**: Searches and launches executables based on the PATH variable, relative, or absolute paths.
- **Logical Operators**: Supports `&&` (AND) and `||` (OR) operators for command chaining, similar to Bash.  
  - `cmd1 && cmd2`: `cmd2` executes only if `cmd1` succeeds.
  - `cmd1 || cmd2`: `cmd2` executes only if `cmd1` fails.
- **Signal Handling**: Handles signals with at most one global variable (for storing the received signal number only).
- **Quoting**: Handles single (`'`) and double (`"`) quotes with appropriate interpretation rules.
    - Single quotes prevent interpretation of all meta-characters.
    - Double quotes prevent interpretation except for `$` (variable expansion).
- **Redirections**:
    - `<`  : Input redirection.
    - `>`  : Output redirection (truncate).
    - `<<` : Here-document (custom delimiter, no history update required).
    - `>>` : Output redirection (append).
- **Pipes**: Implements pipes (`|`) to connect the output of one command to the input of the next.
- **Environment Variables**: Expands variables using `$`, including `$?` for the last exit status, and supports `SHLVL`.
- **Control Characters** (interactive mode):
    - `Ctrl-C`: Displays a new prompt on a new line.
    - `Ctrl-D`: Exits the shell.
    - `Ctrl-\`: Does nothing.
- **Built-in Commands**:
    - `echo` (with `-n`)
    - `cd` (with a path)
    - `pwd`
    - `export`
    - `unset`
    - `env`
    - `exit`

---

## Usage

### Compilation

```sh
make
```

### Running

```sh
./minishell
```

### Exiting

- Type `exit` or press `Ctrl-D` at the prompt.

---

## Requirements

- Only the following external functions are allowed:  
  `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`,  
  `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`,  
  `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`,  
  `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`,  
  `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`,  
  `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`,  
  `tgoto`, `tputs`
- Only one global variable permitted (for signal number).
- **No memory leaks** allowed in your own code.

---

## Project Structure

- `Makefile`: Build rules (`NAME`, `all`, `clean`, `fclean`, `re`)
- `*.h`: Header files
- `*.c`: Source files

---

## Notes

- Features such as unclosed quotes, `\` (backslash), or `;` (semicolon) are **not** required.
- The shell is designed to closely mimic Bash behavior for signals and built-ins, **within the constraints of the project**.
- The use of the `readline` function may cause memory leaks internally, but your own code must be leak-free.
- Now supports `&&`, `||` logical operators and manages the `SHLVL` environment variable.

---

## Author

- [nerovanity](https://github.com/nerovanity) , [mrmo7ox](https://github.com/mrmo7ox)
