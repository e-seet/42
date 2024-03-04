Sorting just 3 numbers:
./push_swap 1 2 3
./push_swap 1 3 2
./push_swap 2 1 3
./push_swap 2 3 1
./push_swap 3 1 2
./push_swap 3 2 1

Work on 5 numbers
Testing random combinations
case 1:
./push_swap 5 3 1 2 4
./push_swap 5 3 1 4 2

case 2 [not done]:
./push_swap 2 5 1 4 3
./push_swap 2 5 1 3 4

./push_swap 3 5 2 1 4
./push_swap 3 5 2 4 1

case 3:
./push_swap 3 1 2 4 5
./push_swap 3 1 2 5 4

case 4:
./push_swap 1 4 2 5 3
./push_swap 1 4 2 3 5

Case 5:
./push_swap 3 2 5 4 1
./push_swap 3 2 5 1 4

./push_swap 4 1 5 3 2
./push_swap 4 1 5 2 3

case 6:
./push_swap 1 2 3 5 4
./push_swap 1 2 3 4 5

## Others

>should not work.
Should return "Error\n"

./push_swap 1 3 dog 35 80 -3
./push_swap a

>these need error? For Now i put as error
>To check these test case
./push_swap 1 2 3 5 67b778 947
./push_swap " 12 4 6 8 54fhd 4354"
./push_swap 1 --    45 32 

>The program should NOT work if it encounters a double number
>these examples should return "Error\n"

./push_swap 1 3 58 9 3
./push_swap 3 03
./push_swap " 49 128     50 38   49"

./push_swap "95 99 -9 10 9"
this example should work because -9 & 9 are not equal

>The program should work with INT MAX & INT MIN
>these examples should work and sort your list
./push_swap 2147483647 2 4 7
./push_swap 99 -2147483648 23 545
./push_swap "2147483647 843 56544 24394"

>should not work since more than max
>these examples should return "Error
./push_swap 54867543867438 3
./push_swap -2147483647765 4 5
./push_swap "214748364748385 28 47 29"

>Nothing has been specified when strings and int are mixed. It's up to you what you want to do. 
>I put ERror
./push_swap "1 2 4 3" 76 90 "348 05"
