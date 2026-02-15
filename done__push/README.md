*This project has been created as part of the 42 curriculum by maryaada.*

# Push_swap

## Description

Push_swap is an algorithmic project whose goal is to sort a list of integers using two stacks and a limited set of operations.

The challenge is not only to sort the numbers correctly, but to do so using the smallest possible number of operations. The project emphasizes algorithmic optimization, data structure manipulation, and complexity analysis.

The program receives a list of integers as arguments and outputs a sequence of instructions that sort the numbers in ascending order using only the allowed stack operations.

This project uses the turk algorithm which utilises cost based calculations to sort using minimal operations for each number.

The data structure used for this project is a single linked list for both stacks and the algorithm works as follows.

*__This project was done without the bonus, only mandatory__*

#### Algorithm Overview
> Push all but three elements from stack A to stack B.
> Sort the remaining three elements in stack A using a sort_three function.
> For each element in stack B:
> Determine its correct target position in stack A.
> Calculate the movement cost for both stacks.
> Select the element with the minimal total cost.
> Execute optimized rotations.
> Push the element back to stack A.
> Perform a final rotation to place the smallest element at the top.

This approach reduces unnecessary movements and improves performance for large input sizes

### Allowed Operations

- `sa`, `sb`, `ss` — swap
- `pa`, `pb` — push
- `ra`, `rb`, `rr` — rotate
- `rra`, `rrb`, `rrr` — reverse rotate

The objective is to sort the stack using these operations.

---

## Instructions

### Compiling the project

To compile, first run the make command to compile the library and get the executable *push_swap*

```bash
make
```

You should now see a *push_swap* executable is created in your directory.

### Running the program

run the *push_swap* executable followed by the test input you would like to see a list of operations printed out on the terminal.

```
./push_swap [insert test input here]
```

to get the number of operations used, you can use the command wc -l after the executable to only print out the number of lines outputted by the program.

```
./push_swap [insert test input here] | wc -l
```

#### Using the Checker

The checker is used to make sure the numbers input are correctly sorted, it's output will be
```
> OK //for correctly sorted
```
or
```
> KO //for incorrectly sorted
```

Download the checker that coincides with the operating system you are using and run it alongside the program like so

```
./push_swap [insert test input here] | ./checker_yourOS [exact same test input here]
```
make sure that both inputs are the exact same.

*In the event the checker shows "permission denied".
Change the permissions of the file by running.
```
chmod +x checker_yourOS
```

and then run the 1st command again.

to make it simpler you can create a variable and run it for both of the executables for consistency like so

```
ARG="[test input here] ./push_swap $ARG | ./checker_yourOS $ARG
```
that way the test input will remain the same for both the program and the checker.

---

### Resources

- 42 push_swap project PDF
- CS50 Data Structures Lecture (for linked lists refresh)
https://www.youtube.com/watch?v=2T-A_GFuoTo&t=27s

- Stack wiki page (provided by project PDF)
https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

- Analysis of algorithms wiki page (provided by project PDF)
https://en.wikipedia.org/wiki/Analysis_of_algorithms

- Stack Data structure and operations by C Programming (to better understand stack behaviour)
https://www.youtube.com/watch?v=Flk5yrlx5Qo&list=PL3v0LM6C85qjLTbGPPYkOhlhGuq_tSLvH

- Implementing a stack in C by Code Vault
https://www.youtube.com/watch?v=8nix1eqoMHM&list=PL3v0LM6C85qjLTbGPPYkOhlhGuq_tSLvH&index=3

- Chatgpt and Deepseek for clarity, further explainations and debugging and generating test cases for each stage of the project like parsing checks.
