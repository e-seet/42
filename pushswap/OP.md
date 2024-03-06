# elements with steps limit

100 max 1001 | 500 1100
4 numbers with max of 7
5 numbers with max of 11
100 number with max 1084 instructions => 3 points
500 numbers with max 6785 instructions =? 4 points

## These are for operations

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

C5

Rotate bot to top
Swap top two [At top: 4,5]
4 1 2 3 5
4 1 3 2 5
4 2 1 3 5
4 2 3 1 5
4 3 1 2 5
4 3 2 1 5

Swap top two
Rotate bot to top
Swap top two [At top: 4,5]
1 4 2 3 5
1 4 3 2 5
2 4 1 3 5
2 4 3 1 5
3 4 1 2 5
3 4 2 1 5

Rotate bot to top
Rotate bot to top
Swap top two
Rotate top to bot [At bot: 4,5]
1 2 4 3 5
1 3 4 2 5
2 1 4 3 5
2 3 4 1 5
3 1 4 2 5
3 1 4 2 5
3 2 4 1 5

No action
1 2 3 4 5
1 3 2 4 5
2 1 3 4 5
2 3 1 4 5
3 1 2 4 5
3 2 1 4 5

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

C1
Swap top 2 [At top: 4, 5]
5 4 1 2 3
5 4 1 3 2
5 4 2 1 3
5 4 2 3 1
5 4 3 1 2
5 4 3 2 1

Swap top 2
Rotate top to bot [5,4]
Swap top 2 [At top: 4, 5]
5 1 4 2 3
5 1 4 3 2
5 2 4 1 3
5 2 4 3 1
5 3 4 1 2
5 3 4 2 1

Rotate bot to top
Swap top 2
Rotate top to bot [At bot: 4,5]
5 1 2 4 3
5 1 3 4 2
5 2 1 4 3
5 2 3 4 1
5 3 1 4 2
5 3 2 4 1

Rotate top to bot [At bot: 4,5]
5 1 2 3 4
5 1 3 2 4
5 2 1 3 4
5 2 3 1 4
5 3 1 2 4
5 3 2 1 4

C2
No action
[At top: 4, 5]
4 5 1 2 3
4 5 1 3 2
4 5 2 1 3
4 5 2 3 1
4 5 3 1 2
4 5 3 2 1

c3
Rotate top to bot
Swap top 2 [At top:  4,5]
1 5 4 2 3
1 5 4 3 2
2 5 4 1 3
2 5 4 3 1
3 5 4 1 2
3 5 4 2 1

Swap top two
Rotate bot to top
Swap top two
Rotate top to bot [At bot 4, 5]
1 5 2 4 3
1 5 3 4 2
2 5 1 4 3
2 5 3 4 1
3 5 1 4 2
3 5 2 4 1

Swap top two
Rotate top to bot [At bot: 4, 5]
1 5 2 3 4
1 5 3 2 4
2 5 1 3 4
2 5 3 1 4
3 5 1 2 4
3 5 2 1 4

Swap top two
Rotate top to bot [At top: 4,5]
4 1 5 2 3
4 1 5 3 2
4 2 5 1 3
4 2 5 3 1
4 3 5 1 2
4 3 5 2 1

Rotate top to bot [At top 4,5]
1 4 5 2 3
1 4 5 3 2
2 4 5 1 3
2 4 5 3 1
3 4 5 1 2
3 4 5 2 1

Rotate top to bot
Rotate top to bot
Swap top two [At top: 4,5]
1 2 5 4 3
1 3 5 4 2
2 3 5 4 1
2 1 5 4 3
3 1 5 4 2
3 2 5 4 1

Rotate bot to top
Rotate bot to top
Swap top two
Rotate bot to top
Swap top two [at top: 4, 5]
1 2 5 3 4
1 3 5 2 4
2 3 5 1 4
2 1 5 3 4
3 1 5 2 4
3 2 5 1 4

C4
Rotate bot to top
Swap top two
Rotate bot to top
Swap top two [At top: 4,5]
4 1 2 5 3
4 1 3 5 2
4 2 1 5 3
4 2 3 5 1
4 3 1 5 2
4 3 2 5 1

Swap top two
Rotate bot to top
Swap top two
Rotate bot to top
Swap top two [At top: 4,5]
1 4 2 5 3
1 4 3 5 2
2 4 1 5 3
2 4 3 5 1
3 4 1 5 2
3 4 2 5 1

Rotate bot to top [At bot: 4,5]
1 2 4 5 3
1 3 4 5 2
2 1 4 5 3
2 3 4 5 1
3 1 4 5 2
3 2 4 5 1

Rotate bot to top
Rotate bot to top
Swap top two [At top: 4, 5]
1 2 3 5 4
1 3 2 5 4
2 1 3 5 4
2 3 1 5 4
3 1 2 5 4
3 2 1 5 4

C5
Rotate bot to top
Swap top two [At top: 4,5]
4 1 2 3 5
4 1 3 2 5
4 2 1 3 5
4 2 3 1 5
4 3 1 2 5
4 3 2 1 5

Swap top two
Rotate bot to top
Swap top two [At top: 4,5]
1 4 2 3 5
1 4 3 2 5
2 4 1 3 5
2 4 3 1 5
3 4 1 2 5
3 4 2 1 5

Rotate bot to top
Rotate bot to top
Swap top two
Rotate top to bot [At bot: 4,5]
1 2 4 3 5
1 3 4 2 5
2 1 4 3 5
2 3 4 1 5
3 1 4 2 5
3 1 4 2 5
3 2 4 1 5

No action
1 2 3 4 5
1 3 2 4 5
2 1 3 4 5
2 3 1 4 5
3 1 2 4 5
3 2 1 4 5
