# To run

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