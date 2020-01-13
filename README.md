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

### Sorting all numbers greater than 5
- We sort our stack A in any convenient way and record the minimum, maximum, beginning of the middle part, the average number, and the end of the middle part
<img src="https://sun9-49.userapi.com/c855424/v855424359/1c2f25/o5XWVU5E300.jpg" data-canonical-src="https://sun9-49.userapi.com/c855424/v855424359/1c2f25/o5XWVU5E300.jpg" width=40% height=40%>
- Then all the numbers except the minimum middle and the maximum group, we throw into the stack B
<img src="https://sun9-47.userapi.com/c855424/v855424359/1c2f5a/ljORdOTOm-4.jpg" data-canonical-src="https://sun9-47.userapi.com/c855424/v855424359/1c2f5a/ljORdOTOm-4.jpg" width=36% height=36%>
- Next, we throw all the numbers except the minimum middle and maximum in the stack B, and sort stack A
<img src="https://sun9-50.userapi.com/c855424/v855424359/1c2fa4/WskyPCoR0vQ.jpg" data-canonical-src="https://sun9-50.userapi.com/c855424/v855424359/1c2fa4/WskyPCoR0vQ.jpg" width=40% height=40%>
- Then we look at all the numbers in stack B and select the best way to insert them into stack A (the minimum number of operations). We are looking at 4 ways to twist the stack to make a <b>pa</b>
<img src="https://sun9-58.userapi.com/c855424/v855424498/1c5862/hiKOkIBnQAY.jpg" data-canonical-src="https://sun9-58.userapi.com/c855424/v855424498/1c5862/hiKOkIBnQAY.jpg" width=110% height=110%>
- After all the numbers from stack B fall into place in stack A, we scroll the stack A so that the minimum number is at the top, considering how best to do it: using <b>ra</b> or <b>rra</b>
<img src="https://sun9-42.userapi.com/c855424/v855424498/1c58b4/hd_DUq-gfdU.jpg" data-canonical-src="https://sun9-42.userapi.com/c855424/v855424498/1c58b4/hd_DUq-gfdU.jpg" width=40% height=40%>

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

## Getting started

### Run the following commands:
#### Compiling

+ To compile
```diff
- make
```
+ To remove objects:
```diff
- make clean
```
+ To remove objects and binary file (program):
```diff
- make fclean
```
+ To re-compile:
```diff
- make re
```
#### Testing

+ To test the function add the rand function to .zshrc
```diff
- function rand{ruby -e "puts ($1 .. $2).to_a.shuffle.join(' ')"}

- ARG=$(rand 0 99); ./push_swap $ARG | ./checker $ARG
```  
+ To check the function for the number of commands
```diff
- ARG=$(rand 0 99); ./push_swap $ARG | wc -l
```  

## Sources

[Sorting algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
