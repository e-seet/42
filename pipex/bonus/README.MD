# To run

## compile it

> make

### First set of commands to test

> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file_bonus"
> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "output_file_bonus"
> ./pipexs "here_doc" "END" "tr a b" "tr b c" "tr c d" "tr d e" "tr e f" "tr f g" "output_file_bonus"

### Second set of commands to test

> ./pipexs "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f"  "output_file_bonus"
> ./pipexs "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "output_file_bonus"
> ./pipexs "in_file_bonus" "tr a b" "tr b c" "tr c d" "tr d e"  "tr e f" "tr f g" "tr g h" "output_file_bonus"
