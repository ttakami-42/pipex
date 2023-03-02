# pipex
It must behave exactly the same as '|'.

## What is pipex?

Program name | pipex
:----------- | :----
Turn in files    | Makefile, \*.h, \*.c
Makefile         | NAME, all, clean, fclean, re
Arguments        | file1 cmd1 cmd2 file2
External funcs   | • open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid<br>• ft_printf and any equivalent YOU coded
Libft authorized | Yes

## Requirement

Your program will be executed as follows:
```sh
./pipex file1 cmd1 cmd2 file2
```
It must take 4 arguments:
* file1 and file2 are file names.
* cmd1 and cmd2 are shell commands with their parameters.
* It must behave exactly the same as the shell command below:
	```sh
	< file1 cmd1 | cmd2 > file2
	```

### Example
```sh
./pipex infile "ls -l" "wc -l" outfile
```
```sh
#Should behave like:
< infile ls -l | wc -l > outfile
```

```sh
./pipex infile "grep a1" "wc -w" outfile
```
```sh
#Should behave like:
< infile grep a1 | wc -w > outfile
```

Your project must comply with the following rules:
* You have to turn in a Makefile which will compile your source files. It must not relink.
* You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
* Your program mustn’t have __memory leaks__.
* If you have any doubt, handle the errors like the _shell command_.

## Bonus requirement

You will get extra points if you:

* Handle multiple pipes.
	```sh
	./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
	```
	```sh
	#Should behave like:
	< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
	```

* Support « and » when the first parameter is "here_doc".
	```sh
	./pipex here_doc LIMITER cmd cmd1 file
	```
	```sh
	#Should behave like:
	cmd << LIMITER | cmd1 >> file
	```

## How Does it Works?

![How_Does_pipex_Work](https://user-images.githubusercontent.com/67182687/206078253-6155a89d-ca1c-48a9-ad7a-78853bbef624.svg)
