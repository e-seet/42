# Test case

Work on 3 numbers. Check Testcase3
Work on 4 numbers. Check Testcase4
Work on 5 numbers. Check Testcase5

## Others

>should not work.
Should return "Error\n"

non numeric
./push_swap 1 3 dog 35 80 -3

duplicated number
./push_swap 1 3 35 80 3 3

./push_swap a

>The program should NOT work if it encounters a double number
>these examples should return "Error\n"

./push_swap 1 3 58 9 3
./push_swap 3 03
./push_swap " 49 128     50 38   49"

this example should work because -9 & 9 are not equal
./push_swap "95 99 -9 10 9"

>The program should work with INT MAX & INT MIN
>these examples should work and sort your list
./push_swap 2147483647 2 4 7
./push_swap 99 -2147483648 23 545
./push_swap "2147483647 843 56544 24394" // no error for this. Since 2147...7 is the max int

ARG="2147483647 2 4 7"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="99 -2147483648 23 545"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2147483647 843 56544 24394"; ./push_swap $ARG | ./checker_Mac $ARG

>should not work since more than max
>these examples should return "Error
./push_swap 54867543867438 3
./push_swap -2147483647765 4 5

ARG="54867543867438 3"; ./push_swap $ARG | ./checker_Mac $ARG

Run push_swap without any parameters. The program must not
display anything and give the prompt back. (Display nothing)
./push_swap

display nothing
./push_swap 2 3

display nothing
./push_swap 0 1 2 3

display nothing
./push_swap 0 1 2 3 4 5 6 7 8 9

Check that the checker program displays "OK" and that the
size of the list of instructions from push_swap is 2 OR 3.
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG

ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG


to check
>these need error? For Now i put as error
>To check these test case
./push_swap 1 2 3 5 67b778 947

// this is not done !! important. This should break and not run
./push_swap " 12 4 6 8 54fhd 4354"

./push_swap 1 --    45 32  // this to checj

more than max int. this should break and not run
./push_swap "214748364748385 28 47 29"
valgrind --leak-check=full ./push_swap "214748364748385 28 47 29" 

>Nothing has been specified when strings and int are mixed. It's up to you what you want to do.
>I put no error
./push_swap "1 2 4 3" 76 90 "348 05"

the following is fixed
ARG=("1" "2" "4" "3" "76 90" "348 05"); ./push_swap "${ARG[@]}"
ARG=("1" "2" "4" "3" "76 90" "348 05"); ./push_swap "${ARG[@]}" | ./checker_Mac "${ARG[@]}"
1 2 4 3 76 90 348 05

### To Check and try / fix

// fixed
// this is not done !! important. This should break and not run
./push_swap " 12 4 6 8 54fhd 4354"

fixed the below:
more than max int. this should break and not run
./push_swap "214748364748385 28 47 29"

check output of this
./push_swap "1 2 4 3" 76 90 "348 05"
ARG="1 2 4 3" 76 90 "348 05"; ./push_swap $ARG | ./checker_Mac $ARG
// the above have error due to the string 
ARG="1 2 4 3 76 90 348 05"; ./push_swap $ARG | ./checker_Mac $ARG
