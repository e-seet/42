# For pipex

make

//pipex, file1, cmd1, cmd2, file2

// compile
> find . -name "*.c" | entr make
// execute
> ./pipex in_file "tr a b" "tr b c" output_file
> ./pipex in_file "ls -l" "wc -l" output_file
> ./pipex in_file "grep file" "wc -w" output_file
> ./pipex in_file "grep file" "wc -l" output_file

// pipex medic test
./pipex in_file "grep Now" "cat" "outs/test-xx.txt"
./pipex "in_file" "wc -w" "cat" "outs/test-xx.txt"

./pipex in_file "grep Now" "cat" "test-xx.txt"
./pipex "in_file" "wc -w" "cat" "test-xx.txt"


Test 16:
./pipex "in_file" "cat" "hostname" "outs/test-xx.txt"
hostname

Test 18:
./pipex "in_file" "grep Now" "head -2" "outs/test-xx.txt"
>grep "Now" in_file | head -2 

20
./pipex "in_file" "grep Now" "wc -w" "outs/test-xx.txt"
>grep "Now" in_file | wc -w

22
./pipex "in_file" "grep Now" "cat" "outs/test-xx.txt"
>grep "Now" in_file
then:
./pipex "in_file" "wc -w" "cat" "outs/test-xx.txt"
>wc -w in_file

Test 25
./pipex "in_file" "notexisting" "wc" "outs/test-xx.txt"
(notexisting is a command that is not supposed to exist)

in_file:
Hello, this is a sample input file.
The file contains some text that can be processed by your program.
You can replace this file with the actual content you want to process.

## For bonus

## Use entr file watcher. Any file changes will automatically be run with "make"

<!-- find . -name "*.c" | entr make -->
make pipex_bonus

### To run the program: Sample commands

### First set of commands

> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file_bonus"
> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "output_file_bonus"
> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "tr e f" "tr f g" "output_file_bonus"

### Second set of commands

> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f"  "output_file_bonus"
> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "output_file_bonus"
> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "tr g h" "output_file_bonus"

- pipexs: executable
- "here_doc": heredoc block
- "END": delimiter to specify end of heredoc
- "tr x1 x2": replace character x1 to character x2
- "output_file_bonus": the file name to append the result from all of the commands

If argc: 9
3: read: p1fd, write: fdpipe1[1]
4: read: fdpipe1[0], write:fdpipe2[1]
5: read: fdpipe2[0], write:fdpipe1[1]
6: read: fdpipe1[0], write:fdpipe2[1]
7: read: fdpipe2[0], write:p2fd

If argc: 10
3: read: p1fd, write: fdpipe1[1]
4: read: fdpipe1[0], write:fdpipe2[1]
5: read: fdpipe2[0], write:fdpipe1[1]
6: read: fdpipe1[0], write:fdpipe2[1]
7: read: fdpipe2[0], write:fdpipe1[1]
8: read: fdpipe1[0], write:p2fd

if argc: 9
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

3:
[3] -1- [4] -2- [5] -1- [6] -2- [7]
[3] -1- [4] -2- [5] -1- [6] -2- [7] -1- [8]
