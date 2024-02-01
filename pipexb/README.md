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
