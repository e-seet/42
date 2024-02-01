# For pipex bonus

## Use entr file watcher. Any file changes will automatically be run with "make"

find . -name "*.c" | entr make

## To run the program: Sample commands

>./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file"

>./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "output_file"

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
