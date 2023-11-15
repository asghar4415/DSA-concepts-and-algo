#include <iostream>

using namespace std;

// Heap is a data structure that is based on the complete binary tree.
// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

// -Heap order property:
//     -Max-heap: the value of each node is less than or equal to the value of its parent, with the maximum-value element at the root.
//     -Min-heap: the value of each node is greater than or equal to the value of its parent, with the minimum-value element at the root.

// -Heap representation:
//     -Array: the parent of the node at index i is at index floor((i-1)/2))
//             the left child of the node at index i is at index 2i+1
//             the right child of the node at index i is at index 2i+2

// -Heap operations:
//     -Insert: insert a new element into the heap
//     -Extract: remove the element with the highest priority from the heap
//     -Heapify: convert an array into a heap
//     -Build: create a heap from an array