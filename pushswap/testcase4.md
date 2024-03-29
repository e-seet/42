Sorting 4 numbers:

Original 3
Sorting just 3 numbers:
./push_swap 1 2 3
./push_swap 1 3 2
./push_swap 2 1 3
./push_swap 2 3 1
./push_swap 3 1 2
./push_swap 3 2 1

Test case of 4:
Push to bot.
./push_swap 4 1 2 3
./push_swap 4 1 3 2
./push_swap 4 2 1 3
./push_swap 4 2 3 1
./push_swap 4 3 1 2
./push_swap 4 3 2 1

Push to top then bot
./push_swap 1 4 2 3
./push_swap 1 4 3 2
./push_swap 2 4 1 3
./push_swap 2 4 3 1
./push_swap 3 4 1 2
./push_swap 3 4 2 1

Rotate last element to top
./push_swap 1 2 4 3
./push_swap 1 3 4 2
./push_swap 2 1 4 3
./push_swap 2 3 4 1
./push_swap 3 1 4 2
./push_swap 3 2 4 1

No need for action.
Just use 3 element to fix
./push_swap 1 2 3 4
./push_swap 1 3 2 4
./push_swap 2 1 3 4
./push_swap 2 3 1 4
./push_swap 3 1 2 4
./push_swap 3 2 1 4

To use
./push_swap 4 2 3 1
./push_swap 3 4 1 2
./push_swap 3 1 4 2
./push_swap 2 1 3 4

ARG="1 2 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
