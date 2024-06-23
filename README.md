# Trie Data Structure

A Trie data structure which uses the **binary representation** of integers for handling multiple queries efficiently.

## Supported Compilers
Works on C++17 and C++20 compilers.

## Functionalities
This TRIE data structure offers the following functions:

* `insert(x,y)`
    - Inserts `y` occurrences of the integer `x`.
    - Default value of `y` is 1.
   
* `erase(x,y)`
    - Erases `y` occurrences of the integer `x`.
    - Default value of `y` is 1.
    
* `count(x)`
    - Returns the number of occurrences of the integer `x`.
    
* `findSmallest(k)`
    - Returns the kth smallest integer.
    - Default value of `k` is 1.
    
* `eraseSmallest(k)`
    - Erases the kth smallest integer.
    - Default value of `k` is 1.
    
* `findGreatest(k)`
    - Returns the kth greatest integer.
    - Default value of `k` is 1.
    
* `eraseGreatest(k)`
    - Erases the kth greatest integer.
    - Default value of `k` is 1. 
    
* `countSmaller(x, y)`
    - For `y = 0`: Returns the count of integers smaller than `x`.
    - For `y = 1`: Returns the count of integers smaller than or equal to `x`.
    - Default value of `y` is 0.

* `countGreater(x, y)`
    - For `y = 0`: Returns the count of integers greater than `x`.
    - For `y = 1`: Returns the count of integers greater than or equal to `x`.
    - Default value of `y` is 0.
    
* `minxor(x)`
    - Returns the minimum value of `x XOR y` where `y` is any integer present in the Trie.
    
* `maxxor(x)`
    - Returns the maximum value of `x XOR y` where `y` is any integer present in the Trie.
    
