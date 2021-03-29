# TernaryTree
code for building and using a ternary tree  

# implementation details
It is similar to a binary search tree.
Each node in the tree contains two ints, a lo and a hi int.
Each node has three child pointers representing ternary trees, the left tree contains 
values less than the lo int,the middle tree values between the lo and the hi int, and the right
tree contains values greater than the hi int

#building and running
On the command line
1. git clone https://github.com/plosique/TernaryTree
2. cd TernaryTree
1. make  
2. ./test <vec_size> 

The ./test exe is an example of how to use this data structure
It takes <vec_size> as a command Line argument. It then builds
an vector of size vec_size and populates it with elements from 0 to <vec_size>-1
After shuffling the vector, its elements are inserted one by one to 
a ternaryTree which then populates another vector with the sorted elements.
The final vector is then verified that it is correctly ordered.  

#TODO
Write sorting algorithm with RandomAccessIterators to match that in algorithm.h
Generalize to K-ary trees through templates
Possibly port to Haskell(though kind (Int -> * ) desired) 



