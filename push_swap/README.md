# push_swap

## What is it?

Push_swap is a program which is designed to sort a list of integers into numerical order in the fewest possible moves using a defined set of operations.

## How does it work?

The program stores the arguments given to it as a linked list (referred to as stack A) and uses a second list (referred to as stack B) to assit in the sorting process. Operations are then performed on these stacks to manipulate their order.
The operations the program uses are as follows:

- pa - Push the top element of stack B to the top of stack A.
- pb - Push the top element of stack A to the top of stack B.
- ra - Rotate stack A one place (the last element wraps around to become the first element).
- rb - Rotate stack B one place (the last element wraps around to become the first element).
- rr - Rotate both stacks at the same time.
- sa - Swap the first and second element of stack A.
- sb - Swap the first and second element of stack B.
- rra - Reverse rotate stack A one place (the first element wraps around to become the last element).
- rrb - Reverse rotate stack B one place (the first element wraps around to become the last element).
- rrr - Reverse rotate both stacks at the same time.

The program will used an algorithm referred to as [´Mechanical Turk´](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) to sort the list. Once this list is sorted stack B will remain empty and the list of the operations that were used will be given on the standard output. This output can then be run through a checker program, such as the one provided by the school or, as in this case, a custom one written as part of the project. 

## How does the checker work?

The checker works by receiving the same list of integers as arguments and then parsing the standard input for the operations to be used. The checker will then run these operations on the list. Once all the operations have been passed it will check if the list is sorted. If the list is sorted it will display on the standard output 'OK!', otherwise it will display 'KO!' if the list is not correctly sorted. If the output of push_swap is passed directly to the checker program it provides an automated way to check that the program is functioning correctly. 

> [!NOTE]
> This is intended as a guide only. Writing and understanding your own code is better than copying code.