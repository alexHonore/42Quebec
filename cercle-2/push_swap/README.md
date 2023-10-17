# push_swap
Using radix sort and linked list: 
[Tutorial of push_swap in radix sort](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

### Treat numbers with a binary aproach

Because push_swap let us 2 stacks, we can't sort the numbers a decimal way, 2 stacks = base 2 = binary! The radix sort algorithm is for positive only integers. So, because this projet have to handle negatives, the numbers will be simplified by their indexes(assigned in ascending order) to begin with.

The stack a will be treated as the 1's box </br>
The stack b will be treated as the 0's box

The smallest number have an index of 0, the next smallest gets 1 etc.
With this idea, we can simplify any list of integers to make them in the range [0,N[ where N is the size of the list).

Don't forget that the numbers are treated based of their given indexes, i-th digit is the index and not the number value

*Radix sort operations looped until sorted*

{

At the i-th digit from the right(eg: 5 in binary is 0101, the i-th digit is 1. 10 is 1010 and the i-th digit is 0), if the i-th digit of the top number of stack A is 0, we perform `pb` to put this number in stack B. Else, we perform `ra` to leave it in stack A. After we perform one operation on each number, each of them is in the box that corresponds to its digit, as how we put numbers in the boxes in radix sort.

After that, we perform `pa` until there are no numbers in stack B, as we connect the numbers in radix sort.

}

Repeated the same procedure for every bit and after that got the sorted numbers in the stack a.

## Better for comprehention

|   |                          |               
| ----- | ----------------------------------- 
| &     | Bitwise AND                              
| l (vertical line)  | Bitwise OR                             
| ^     | Bitwise XOR                    
| ~     | Bitwise NOT                              
| <<    | Bitwise Left Shift                             
| >>    | Bitwise Right Shift                          
| 0001  | In decimal is 1                     
| 0010  | In decimal is 2                     
| 0100  | In decimal is 4                     
| 1000  | In decimal is 8                     
| 1111  | In decimal is 15 (sum the ones. 1 in right, *2 each time to the left)            
![image](https://user-images.githubusercontent.com/98293124/192162543-66624c9b-a0d9-49c0-b367-9a83e64521b2.png) | ![image](https://user-images.githubusercontent.com/98293124/192162672-b28e4022-07cf-41bc-93c4-f00e577e5ae2.png)
![image](https://user-images.githubusercontent.com/98293124/192162677-b094fd7c-7c2c-42ad-8817-b1bb2d7179f1.png) | ![image](https://user-images.githubusercontent.com/98293124/192162685-4d68fb37-1300-4c30-a623-c0c0fdbbcca6.png)
images from [here](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) and [here](https://techvidvan.com/tutorials/python-bitwise-operators/) | ![image](https://user-images.githubusercontent.com/98293124/192163501-cf945a5e-17e5-432b-b303-96d2c6128100.png)


