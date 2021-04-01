# Dealing with Large Numbers even beyond the range of long long int

### Problem Statement
Adding two numbers is trivial. In C/C++, the simple mathematical expression such as `sum = a + b` will add variable 'a' and 'b' and put the result in the variable 'sum'. 
Your task is to add two very large numbers which are **beyond the capacity** to be stored in any existing integer data types in C/C++ like long int, etc . 
Write a function `largeAdd(ni,n2)` to achieve such very large digit additions. You should save your output (sum) in a text file *“sum.txt”*.


#### Hint:
Idea is to treat such a large number as a string of characters each consisting of digits in the range 0-9. 
Hence you should take two input numbers (strings) say, “2345” & “9876” and perform digitwise addition (perform char to int conversion, add and then store the result back as char) 
as we do addition manually, finally display the sum “12221”as a string.
