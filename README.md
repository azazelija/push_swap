# push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## Visualization

![](https://github.com/azazelija/push_swap/blob/master/fculator.gif)

## Algorithm

### Sorting three numbers
- We find the maximum elements index of the stack A
- If it is at the top, do <b>ra</b>, if in the middle do <b>rra</b>
- Then we compare the first two numbers with each other and change their places, if necessary, using <b>sa</b>
![](https://sun9-65.userapi.com/c206624/v206624884/2e82f/oFLwbFSIPyE.jpg)

### Sorting five or less numbers
- We find the maximum element index of the stack A
- Сompare the first number in the stack. If number less than three maximum throw in the stack B with <b>pb</b>, else apply <b>ra</b>
- Then we sort the array A with the previously written sorting algorithm for 3 numbers
- In stack b, we find the maximum element and compare it with the first number in stack b, if they match, then we do <b>pb</b> <b>pb</b>, otherwise <b>sb</b>
![](https://sun9-25.userapi.com/c206624/v206624381/2f6e7/6PeTsyyYKfQ.jpg)

## Restrictions

| Stack size | Operations |
| :--------: | :--------: | 
| 3 integers | no more than 2-3 |
| 5 integers | no more than 12 |
| 100 integers | no more than 700 |
| 500 integers | no more than 5300 |

## Instructions

| instructions| Description |
| :--------: | :--------: | 
| sa | swap first two elements of stack A |
| sb | swap first two elements of stack B |
| ss | sa and sb at the same time |
| pa | pops the first elememt on B and puts it on top of A |
| pb | pops the first elememt on A and puts it on top of B |
| ra | rotates stuck A up by one |
| rb | rotates stuck B up by one |
| rr | rotates both A and B up by one |
| rra | rotates stuck A down by one |
| rrb | rotates stuck B down by one |
| rrr | rotates both A and B down by one |

## Sources

[Sorting algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
