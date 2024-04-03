# Permutation for 4 and 5

C1: 5 at top
ARG="5 4 1 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 2 3 4"; ./push_swap $ARG | ./checker_linux $ARG

./push_swap 5 4 1 2 3
./push_swap 5 1 4 2 3
./push_swap 5 1 2 4 3
./push_swap 5 1 2 3 4

C2: 5 at 2nd
ARG="4 5 1 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 3 4"; ./push_swap $ARG | ./checker_linux $ARG

./push_swap 4 5 1 2 3
./push_swap 1 5 4 2 3
./push_swap 1 5 2 4 3
./push_swap 1 5 2 3 4

C3:
ARG="4 1 5 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 5 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 5 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 5 3 4"; ./push_swap $ARG | ./checker_linux $ARG

./push_swap 4 1 5 2 3
./push_swap 1 4 5 2 3
./push_swap 1 2 5 4 3
./push_swap 1 2 5 3 4

C4
ARG="4 1 2 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 2 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 5 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 3 5 4"; ./push_swap $ARG | ./checker_linux $ARG

./push_swap 4 1 2 5 3
./push_swap 1 4 2 5 3
./push_swap 1 2 4 5 3
./push_swap 1 2 3 5 4

c5
ARG="4 1 2 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 2 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 4 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 2 4 5"; ./push_swap $ARG | ./checker_linux $ARG
./push_swap 4 1 2 3 5
./push_swap 1 4 2 3 5
./push_swap 1 2 4 3 5
./push_swap 1 3 2 4 5

## All permutation of 1 2 3 4 5

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5
1 4 2 5 3
1 4 3 2 5
1 4 3 5 2
1 4 5 2 3
1 4 5 3 2
1 5 2 3 4
1 5 2 4 3
1 5 3 2 4
1 5 3 4 2
1 5 4 2 3
1 5 4 3 2

2 1 3 4 5
2 1 3 5 4
2 1 4 3 5
2 1 4 5 3
2 1 5 3 4
2 1 5 4 3
2 3 1 4 5
2 3 1 5 4
2 3 4 1 5
2 3 4 5 1
2 3 5 1 4
2 3 5 4 1
2 4 1 3 5
2 4 1 5 3
2 4 3 1 5
2 4 3 5 1
2 4 5 1 3
2 4 5 3 1
2 5 1 3 4
2 5 1 4 3
2 5 3 1 4
2 5 3 4 1
2 5 4 1 3
2 5 4 3 1

3 1 2 4 5
3 1 2 5 4
3 1 4 2 5
3 1 4 5 2
3 1 5 2 4
3 1 5 4 2
3 2 1 4 5
3 2 1 5 4
3 2 4 1 5
3 2 4 5 1
3 2 5 1 4
3 2 5 4 1
3 4 1 2 5
3 4 1 5 2
3 4 2 1 5
3 4 2 5 1
3 4 5 1 2
3 4 5 2 1
3 5 1 2 4
3 5 1 4 2
3 5 2 1 4
3 5 2 4 1
3 5 4 1 2
3 5 4 2 1

4 1 2 3 5
4 1 2 5 3
4 1 3 2 5
4 1 3 5 2
4 1 5 2 3
4 1 5 3 2
4 2 1 3 5
4 2 1 5 3
4 2 3 1 5
4 2 3 5 1
4 2 5 1 3
4 2 5 3 1
4 3 1 2 5
4 3 1 5 2
4 3 2 1 5
4 3 2 5 1
4 3 5 1 2
4 3 5 2 1
4 5 1 2 3
4 5 1 3 2
4 5 2 1 3
4 5 2 3 1
4 5 3 1 2
4 5 3 2 1

5 1 2 3 4
5 1 2 4 3
5 1 3 2 4
5 1 3 4 2
5 1 4 2 3
5 1 4 3 2
5 2 1 3 4
5 2 1 4 3
5 2 3 1 4
5 2 3 4 1
5 2 4 1 3
5 2 4 3 1
5 3 1 2 4
5 3 1 4 2
5 3 2 1 4
5 3 2 4 1
5 3 4 1 2
5 3 4 2 1
5 4 1 2 3
5 4 1 3 2
5 4 2 1 3
5 4 2 3 1
5 4 3 1 2
5 4 3 2 1

ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 3 5 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 4 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 4 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 5 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 5 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 2 4 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 2 5 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 4 2 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 4 5 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 5 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 5 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 2 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 2 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 3 2 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 3 5 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 5 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 5 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 3 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 3 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 4 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 3 4 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 3 5 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 4 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 4 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 5 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 5 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 1 4 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 1 5 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 4 1 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 4 5 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 5 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 1 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 1 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 3 1 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 3 5 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 5 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 5 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 5 1 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 5 1 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 5 3 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 5 3 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 5 4 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 5 4 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 2 4 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 2 5 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 4 2 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 4 5 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 5 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 5 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1 4 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1 5 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 4 1 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 4 5 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 5 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 1 2 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 1 5 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 2 1 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 2 5 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 5 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 5 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 5 1 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 5 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 5 2 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 5 2 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 5 4 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 5 4 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 2 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 2 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 3 2 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 3 5 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 5 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 5 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 1 3 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 1 5 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 3 1 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 3 5 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 5 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 5 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 1 2 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 1 5 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 2 1 5"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 2 5 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 5 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 5 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 5 1 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 5 1 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 5 2 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 5 2 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 5 3 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 5 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 2 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 3 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 3 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 1 4 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 2 1 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 2 1 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 2 3 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 2 3 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 2 4 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 2 4 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 3 1 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 3 2 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 3 2 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 3 4 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 3 4 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 4 1 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 4 1 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 4 2 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 4 2 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 4 3 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
