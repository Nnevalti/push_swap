# Push_swap and Checker :
 
## Checker :
    
Takes integers as arguments put them in a stack A and initialise an empty stack B. It then reads instructions on the standard output. Once read, checker executes them and displays OK if stack A is sorted. Otherwise, it will display KO.

## Push_swap :
    
Calculates and print on the standard output the smallest number of operation needed to sort Pile A.
    
## Operation available:
    
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

- ss : sa and sb at the same time.

- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

- rr : ra and rb at the same time.

- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
    
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

- rrr : rra and rrb at the same time.

## Build the project:

`make`

## Get a shuffled list:

`ARG='ruby -e "puts (1..130).to_a.shuffle.join(' ')"'`

## Execute the programs:

`./push_swap $ARG | ./checker $ARG`

---

# [Push_swap_tester.sh](https://github.com/Nnevalti/push_swap_tester)

*(If you just want the script click the title above)*

This script will test checker and push_swap multiple times for different range and then display the result of each tested range. (number of correct answers, average number moves, minimum and maximum move used to sort the stack) It will generate a random list of numbers for each test.

**Note:** The script worked under Linux Xubuntu (42 VirtualMachine). It doesn't work on MacOS or other Linux distribution. You can always fork the project and adapt it if you want.

## Usage:	
`sh push_swap_tester.sh [OPTIONS]`

## Options:

> **-r, --range RANGE_LIST** <br>
> Use a custom RANGE_LIST to test. RANGE_LIST must be a string of digits. ex: "1 2 3"
> 
> **-n, --nb-test NB_TEST** <br>
> Test each range NB_TEST times.
> 
> **-b, --bonus** <br>
>	Test reverse sorting bonus.
