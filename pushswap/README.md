# PushSwap

## Running the file

find . -name "*.c" | entr make

## Command to run in terminal

>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG

1. Push first 2 elements to stack b irregardless what.
2. Then we sort the Stack 1 and insert into stack A if required from stack b.

## Operations

- sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.

- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

- ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
- rr : ra and rb at the same time.

- rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
- rrr : rra and rrb at the same time

## examples of operations

./push_swap 2 1 3 6 5 8

init a and b
2
1
3
6
5
8
a b

after SA:
1
2
3
6
5
8
a b

PB, PB, PB:
6 3
5 2
8 1
a b

RA, RB:
5 2
8 1
6 3
a b

RRA RRB (equiv. to rrr):
6 3
5 2
8 1
a b

SA:
5 3
6 2
8 1
a b

Exec pa pa pa:
1
2
3
5
6
8
a b

./push_swap 2 1 3 6 5 8

Means 2 is at the top of the stack. [Front of the linked list]

### References

> <https://github.com/o-reo/push_swap_visualizer>
> <https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a>
> <https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e>
> <https://github.com/python/cpython/blob/main/Objects/listobject.c>

pushswap
<https://sharkigamers.github.io/pushswap_epitech_project/>
<https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e>

tester
<https://github.com/julien-ctx/push-swap-tester>
<https://github.com/LeoFu9487/push_swap_tester>
