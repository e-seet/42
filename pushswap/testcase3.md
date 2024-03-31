# Test cases

Sorting just 3 numbers:
./push_swap 1 2 3
./push_swap 1 3 2
./push_swap 2 1 3
./push_swap 2 3 1
./push_swap 3 1 2
./push_swap 3 2 1

ARG="1 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG