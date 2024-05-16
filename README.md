This is my code for the 42 project, push_swap.

Final score: 125/100

The aim of the project is to sort a given stack of numbers using only the allowed "moves" (more details in en.dubject.pdf). 
The numbers must be sorted in as few "moves" as possible.

In order to move a number from one stack to the other, that number has to be at the top of it's stack. 
If you want to move across a number that is not at the top of it's stack, you must either rotate or reverse rotate the stack
as many times as it takes for the desired number to reach the top of the stack.

I have used the approach of moving most numbers into stack "b" and then at each iteration, calculating which number can
be moved into it's correct position in stack "a".

I have used a few optimisations to help with the sorting.

Firstly, I calculate the longest incresaing subsequence that exists in the original set of numbers. I leave these numbers
in place in stack "a" when moving numbers to "b" as they are already sorted as this saves unnecessary moves.

I also use the approach of breaking the numbers up into chunks when moving them to "b" as this helps sorting them back to
"a" more efficiently. I sort the numbers twice before my final sort, once with the chunks in "b" being highest numbers at
tho top, middle numbers in the middle, and low numbers at the bottom, and then again in reverse (lowest numbers at top).

I then compare the results from the two different "pre-sorts" and sort the numbers a final time using the most efficient approach.

Base on my tests, results are:
3 numbers: less than 3 moves
5 numbers: usally less than 10, never more than 12
100 numbers: usually less than 600, never more than 700 (full marks)
500 numbers: usually less than 5000, never more than 5500 (full marks)

I have also completed the bonus which is to make a copy of the "checker" provided with the project. This bonus was incredibly easy
as we have already written almost all the code needed for it (executing moves). I just had to refactor a bit and add a function
to take the instructions from the standard input.
