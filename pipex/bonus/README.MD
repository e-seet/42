# To run

check for heredoc portion
valgrind ./pipex in_file "tr a b" "tr e l" output_file
valgrind ./pipex in_file "ls -l" "grepx" output_file
valgrind ./pipex in_file "grepx" "ls -l" output_file
valgrind ./pipex in_file "grep x" "ls -l" output_file
valgrind ./pipex in_file "grep Hello" "wc -l" output_file
valgrind ./pipex in_file "grep Hello" "wc -w" output_file
valgrind ./pipex in_file "ls -l" "wc -l" output_file

Expected: Does not run at all. Return in_file:permission denied
chmod -xr in_file
valgrind ./pipex in_file "tr a b" "tr b c" output_file

Expected: content still get written inside
Chmod -XR output_file
< in_file ls -l | grep eddie > output_file_bonus

valgrind ./pipex in_file "tr a b" "ls -l" output_file
valgrind ./pipex in_file "tr a b" "tr b c" output_file
valgrind ./pipex in_file "ls "-l "grepx" output_file
valgrind ./pipex in_file "grepx" "ls -l" output_file
valgrind ./pipex in_file "grep x" "ls -l" output_file
valgrind ./pipex in_file "grep Hello" "wc -l" output_file
valgrind ./pipex in_file "grep Hello" "wc -w" output_file
valgrind ./pipex in_file "ls -l" "wc -l" output_file
valgrind ./pipex in_file "ls -l" "Mar" output_file


Expected: Does not run at all. Return in_file:permission denied
Chmod -XR in_file

valgrind ./pipex in_file "tr a b" "tr b c" output_file
Expected: content still get written inside

Chmod -XR output_file
valgrind ./pipex in_file "tr a b" "ls -l" output_file

## Bonus [in_file]

valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "tr a b" "ls -l" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "tr e o" "tr o a" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "tr e o" "tr o a" "tr a d" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "tr e o" "tr o a" "tr a d" "tr d e" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "tr e o" "tr o a" "tr a d" "tr d e" "tr e f" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "ls "-l "grepx" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "grepx" "ls -l" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "grep x" "ls -l" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "grep Hello" "wc -l" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "grep Hello" "wc -w" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "ls -l" "wc -l" output_file
valgrind --leak-check=full --show-leak-kinds=all  ./pipex_bonus in_file "ls -l" "grep Mar" output_file


Expected: Does not run at all. Return in_file:permission denied
chmod -xr in_file

valgrind ./pipex in_file "tr a b" "tr b c" output_file
Expected: content still get written inside

chmod -xr output_file
valgrind ./pipex in_file "tr a b" "ls -l" output_file

## For Heredoc

// just normal ls
valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "tr a b" "ls -l" output_file

// change heredoc input's a->b b->c
valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" output_file

// does not return anything due to failed grepx
valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "ls -l" "grepx" output_file

// just list stuff
valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "grepx" "ls -l" output_file

// just list stuff
valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "tr a b" "ls -l" output_file

valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "grep x" "ls -l" output_file

grab Hello from input
valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "grep Hello" "wc -l" output_file

valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "grep Hello" "wc -w" output_file

valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus "here_doc" "END" "ls -l" "wc -l" output_file

Chmod -XR output_file
valgrind --leak-check=full --show-leak-kinds=all ./pipex "here_doc" "END" "tr a b" "ls -l" output_file


## compile it

> make

### First set of commands to test

> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file_bonus"
> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "output_file_bonus"
> ./pipex_bonus "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "tr e f" "tr f g" "output_file_bonus"

### Second set of commands to test

> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f"  "output_file_bonus"
> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "output_file_bonus"
> ./pipex_bonus "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "tr g h" "output_file_bonus"

 < in_file ls -l | grep eddie > output_file_bonus 