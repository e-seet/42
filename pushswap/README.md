# PushSwap

## Running the file

find . -name "*.c" | entr make

## Command to run in terminal

>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK

Skerritt:
1 If the array we are trying to sort has fewer than 64 elements in it, Timsort will execute an insertion sort.

2 If the list is larger than 64 elements than the algorithm will make a first pass through the list looking for parts that are strictly increasing or decreasing. If the part is decreasing, it will reverse that part.

Important: run.length >= minRun

Eg:
For 2112 Elements
If we use a minRun = 32, we need 66 runs

The first 64 runs merge perfectly into single run of length 2048.
Then we have 2 runs with length 2048 and 64, which requires considerable data movement to put in place those 64.

Solution: Choose a larger minRun: 33, which is more likely to result in 64 runs, each length of 33.

ran: 5 6 7 8 [consecutive increasing / decreasin numbers]
minrun: number of elements to make it efficient

The ran is not enough for minrun
1.So if the ran does not hit the minrun requirement, just add more elements inside.
Then sort it using binary insertion / insertion sort etc..

If ran > minrun
2. just continue adding.
Note: if the ran is in descending order, the ran will be reversed

Rewriting

1.If the run is less than a chosen "minrun" size, TimSort uses InsertionSort to bulk it up to minrun elements.
2.The value of minrun is calculated such that, where n is the size of an array, n/minrun is a power of two or slightly less than a power of two, thus ensuring balanced merges on random data.

Insertion sort:
If the run is 33 [33 items consecutively increasing / decreasing] and minrun is 50,
we use insertion sort and grab another (50 - 33 = 17) 17 elements to add in.
Take the new element, put it into the right position in stack b

Get sorted runs and merge them together.
if 7 numbers are consecutive from run b, it looks for first element in run a and try to find it in run b. Everything between .. and .. can be copied over.

Rules for merging
1.A > B + C
2.B > C

Last run < Second to last run
Last run + Second to last run < Third to last run

### Other references

> <https://www.youtube.com/watch?v=_dlzWEJoU7I>
> <https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing>

### Function prototypes

utils.c
void initstack(t_stack *stack);
int  isempty(t_stack* stack);
void addtoback(t_stack* stack, int value);
int  pop(t_stack *stack);
void displaystack(t_stack* stack);

utils2.c
int countElements();

Operations.c and Operations2.c
These are for operations:

<SA/SB> Swap first 2 elements
void swap_top_two(t_stack *stack);
void ss(t_stack*a, t_stack *b);

<PA/PB> 
PA: Take the first element at the top of b and put it at the top of a.
PB: Take the first element at the top of a and put it at the top of b.
void pb(t_stack*a, t_stack *b);
void pa(t_stack*a, t_stack*b);

<RA/RB>  First element becomes the last one.
void rotate_stack(t_stack*stack);
void rr(t_stack *a, t_stack*b);

<RRA/RRB> last element becomes the first one.
void reverse_rotate_stack(t_stack *stack);
void rrr(t_stack*a, t_stack *b);
t_node*ft_rralastnode(t_node *head, int tonull);  // ignore this

Currently working on:
Sorting just 3 numbers:
./pushswap 1 2 3
./pushswap 1 3 2
./pushswap 2 1 3
./pushswap 2 3 1
./pushswap 3 1 2
./pushswap 3 2 1

Work on 5 numbers
Testing random combinations
./pushswap 3 2 5 4 1
./pushswap 4 1 5 3 2
./pushswap 2 5 1 4 3
./pushswap 5 3 1 2 4
./pushswap 1 4 2 5 3
./pushswap 3 5 2 1 4

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

./pushswap 2 1 3 6 5 8

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

./pushswap 2 1 3 6 5 8

Means 2 is at the top of the stack. [Front of the linked list]

### References

> <https://github.com/o-reo/push_swap_visualizer>
> <https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a>
> <https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e>
> <https://github.com/python/cpython/blob/main/Objects/listobject.c>

Tim sort
> 1 <https://skerritt.blog/timsort/>
> 2 <https://www.baeldung.com/cs/timsort>
> 3 <https://probablydance.com/2016/12/27/i-wrote-a-faster-sorting-algorithm/>
> 4 <https://ericmervin.medium.com/what-is-timsort-76173b49bd16>
> 5 <https://www.educative.io/answers/what-is-timsort>
> 6 <https://www.javatpoint.com/tim-sort>
> 7 <https://medium.com/@rylanbauermeister/understanding-timsort-191c758a42f3>
> 8 <https://probablydance.com/2016/12/27/i-wrote-a-faster-sorting-algorithm/>
> 9 <https://www.geeksforgeeks.org/timsort/>
> 10 <https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399?source=post_page-----191c758a42f3-------------------------------->
> 11 <https://bugs.python.org/file4451/timsort.txt?ref=skerritt.blog>
>12 <https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e>

important: 11, 12
