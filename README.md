This is my code for the 42 project, push_swap.

I've tried a few different approaches already but this one is the best (least number of operations required) so far.
Still going to play around a bit as there are a few things that don't work as expected but the code does work overall.

Number of instructions to sort:
3 : 2
5 : 7-11
100 : 570 - 680
500 : 4800 - 5400

Unfortunately, these numbers are not guaranteed and it will exceed limits around 1% of the time, tyring to fix this.

I have included the checker provided by the school but will make my own in the near future.

The approach is quite simple. First, I make a sorted copy of the array as this is necessary for the next step.

Next, I start to split array a. Any number in the last third (highest numbers) of the sorted array goes to the bottom of 
the second array (array b), any number in the middle third of the sorted array goes to the top of array b, and
any number from the first third (lowest numbers) goes to the bottom of the first array (array a).

Once that is done, I push all the numbers from array a (except for the lowest 5 numbers) into array b. Array b now contains
the lowest value third of numbers (minus the 5 that are still in array a) on top, the middle third of numbers in the middle
and the biggest numbers at the bottom. This makes sorting them into array a more efficient.

The final five numbers get sorted and we turn our attention to array b.

Before pushing any number from array b to array a, we calculate, for every number in array b, how many moves would be
required on both arrays to get that number into it's correct position. Once we've found the most efficient move, we
perform the required operations to move that number into it's sorted place in array a.
