# For pipex bonus

## Use entr file watcher. Any file changes will automatically be run with "make"

find . -name "*.c" | entr make

### To run the program: Sample commands

### First set of commands

> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file"
> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "output_file"
> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "tr e f" "tr f g" "output_file"

### Second set of commands

> ./pipexs "infile" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f"  "output_file"
> ./pipexs "infile" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "output_file"
> ./pipexs "infile" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "tr g h" "output_file"

- pipexs: executable
- "here_doc": heredoc block
- "END": delimiter to specify end of heredoc
- "tr x1 x2": replace character x1 to character x2
- "output_file": the file name to append the result from all of the commands

### utils.h

s_pipex{
p1fd: input file
p2fd: Output file

pid3: Used to determine	
**argvs3: Get the current command
fdpipe1[2]: First set of pipe
fdpipe2[2]: Second set of pipe
curr: current process that we are working on
argc: number of argument passed into the main
*delimiter: Used to store the string required as a delimiter
heredocwritefd: fd to write file

*path: The Path from the paths[]
**paths: The paths splitted from "path"
}

#### utils.c

setstructure:  Basic initialization of variables

linechecker: check if the last character is a \n and subtract accordingly. Go to the position before \0 and check if it is a \n

heredoccmd:  Get the next line from the terminal until it hits the delimiter [1.check the string by strncmp and the length]

findprocesspath: Find the actual path that can access

findpath: Find the path with "PATH=" in envp[i]. Then store in the struct's path

#### main.c

p3child: execute the command [path: the access path, argv: the terminal command, envp: environment pointer]

dup2child: Based on the current process, assign the correct piping through dup2

refactormain: Get the argument from the terminal, fork the process, switch to the right pipe and execute the 
command in the child process

main: setup structure, Check if the command involves heredoc, while loop to execute and do all the requried commands in the terminal

#### Status

### Second set of commands [no issues]

> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file"
> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "output_file"
> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "tr e f" "output_file"
> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "tr e f" "tr f g" "output_file"

If argc: 9
curr:
3: read: p1fd, write: fdpipe1[1]
4: read: fdpipe1[0], write:fdpipe2[1]
5: read: fdpipe2[0], write:fdpipe1[1]
6: read: fdpipe1[0], write:fdpipe2[1]
7: read: fdpipe2[0], write:p2fd

If argc: 10
curr:
3: read: p1fd, write: fdpipe1[1]
4: read: fdpipe1[0], write:fdpipe2[1]
5: read: fdpipe2[0], write:fdpipe1[1]
6: read: fdpipe1[0], write:fdpipe2[1]
7: read: fdpipe2[0], write:fdpipe1[1]
8: read: fdpipe1[0], write:p2fd

3 is fixed.
4 is even so pipe 1
5 is odd so pipe 2

if argc: 9
curr:
2: read: p1fd, write: fdpipe1[1]
3: read: fdpipe1[0], write:fdpipe2[1]
4: read: fdpipe2[0], write:fdpipe1[1]
5: read: fdpipe1[0], write:fdpipe2[1]
6: read: fdpipe2[0], write:fdpipe1[1]
7: read: fdpipe1[0], write:p2fd

if argc: 10
2: read: p1fd, write: fdpipe1[1]
3: read: fdpipe1[0], write:fdpipe2[1]
4: read: fdpipe2[0], write:fdpipe1[1]
5: read: fdpipe1[0], write:fdpipe2[1]
6: read: fdpipe2[0], write:fdpipe1[1]
7: read: fdpipe1[0], write:fdpipe2[1]
8: read: fdpipe2[0], write:p2fd

To solve it:
2:
[2] -0- [3] -1- [4] -2- [5] -1- [6] -2- [7]
[2] -0- [3] -1- [4] -2- [5] -1- [6] -2- [7] -1- [8]

7-2 = 5 % 2 = odd
8-2 = 6 % 2 = even

3:
[3] -1- [4] -2- [5] -1- [6] -2- [7]
[3] -1- [4] -2- [5] -1- [6] -2- [7] -1- [8]

<!-- algo: curr - start = remainder. remainder % 2  -->
<!-- to fix command with infile -->
### Got issues

> ./pipexs "infile" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f"  "output_file"
> ./pipexs "infile" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "output_file"
> ./pipexs "infile" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "tr g h" "output_file"

infile [2:read from fd, write to pipe1] → [3:read from ,write to pipe2] →p2 [4:pipe1] ⇒ [5:pipe2] → [6:pipe1] ⇒ [7:pipe2]

Using heredoc: Need to check refactoring of code. Something breaks after refactoring.
