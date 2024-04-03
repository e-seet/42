# For pipex

make

//pipex, file1, cmd1, cmd2, file2

compile in bash
> find . -name "*.c" | entr make

Evaluation Test
This test checks for character replacement
> ./pipex in_file "tr a b" "tr b c" output_file

This test check for the file n directory using ls -l.
Then wc -l to find out how many lines are there
> ./pipex in_file "ls -l" "wc -l" output_file

This test checks for Hello in the in_file.
Then proceed with the command wc -w to count number of words
> ./pipex in_file "grep Hello" "wc -w" output_file

This test checks for Hello in the in_file.
Then proceed with the command wc -w to count number of lines
> ./pipex in_file "grep Hello" "wc -l" output_file

Extra tests
 < in_file tr a b | tr b c > output_file
./pipex in_file "tr a b" "tr b c" output_file

< in_file grep x | ls -l > output_file
./pipex in_file "grep x" "ls -l" output_file

// for bonus
make pipex_bonus

First set of commands
> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file_bonus"
> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "output_file_bonus"
> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "tr e f" "tr f g" "output_file_bonus"

Second set of commands
> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f"  "output_file_bonus"
> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "output_file_bonus"
> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "tr g h" "output_file_bonus"

// pipex test
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

from pipex-tester
../pipex "assets/deepthought.txt" "grep Now" "cat" "outs/test-xx.txt"
../pipex "assets/deepthought.txt" "wc -w" "cat" "outs/test-xx.txt"

bash command:
grep Now "assets/deepthought.txt" | cat > "outs/test-xx.txt"
wc -w < "assets/deepthought.txt" > "outs/test-xx.txt"

Test 25
./pipex "in_file" "notexisting" "wc" "outs/test-xx.txt"
(notexisting is a command that is not supposed to exist)

in_file:
Hello, this is a sample input file.
The file contains some text that can be processed by your program.
You can replace this file with the actual content you want to process.

>pipex medic

The following have errors as it does not have a file nor follow the required format. Should behave like: < infile ls -l | wc -l > outfile
{ ARGS("grep Hello", "awk \"{count++} END {print count}\""), DEFAULT_ENV, "Hello World!\nHello World!\n" },
{ ARGS("grep Hello", "awk '\"{count++} END {print count}\"'"), DEFAULT_ENV, "Hello World!\nHello World!\n" },
{ ARGS("grep Hello", "awk \"'{count++} END {print count}'\""), DEFAULT_ENV, "Hello World!\nHello World!\n" }

this works:
./pipex "in_file" "grep Hello" "awk {count++} END {print count}" outfile

test:
./pipex "in_file" "grep Hello" "awk '{count++} END {print count}'" outfile

test 5
< input grep Hello | awk '{count++} END {print count}' > output
 ./pipex input "grep Hello" "awk '{count++} END {print count}'" output
<!-- returns 2 -->

test 6
< input grep Hello | awk "{count++} END {print count}" > output
./pipex input "grep Hello" 'awk "{count++} END {print count}"' "output"
<!-- returns 2 -->

<!-- test 7 -->
< input grep Hello | awk '"{count++} END {print count}"' > output

 <!-- return
 Hello World 
 Hello World-->

./pipex in_file "grep Hello" awk {count++} END {print count}  "outfile"
Failed ^

test 8?
< input grep Hello | awk "'{count++} END {print count}'" > output

For the error set
{ ARGS("grep Hello", "wc -l"), DEFAULT_ENV, NULL },
{ ARGS("grep Hello", "wc -l"), NULL_ENV, "Hello World!\n" },
{ ARGS("fizzBuzz", "ls -l src/"), DEFAULT_ENV, "Hello World!\n" },
{ ARGS("ls -l src/", "buzzFizz"), DEFAULT_ENV, "Hello World!\n" },
{ ARGS("fizzBuzz", "wc -l"), NULL_ENV, "Hello World!\n" },
{ ARGS("grep Hello", "buzzFizz"), NULL_ENV, "Hello World!\n" }

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
