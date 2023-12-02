#include <iostream>


using namespace std;

//Hash function: 
//It is a function that converts a given big input key to a small practical integer value.
//The values returned by a hash function are called hash values, hash codes, hash sums, or simply hashes.
//The hash function uses the hash code to index into an array called the hash table,  from which the desired value can be found.

//Hash code:  It is a number generated from a string of text. The hash code is used to index a hash table.

//Hash table: It is a data structure that implements an associative array abstract data type, a structure that can map keys to values.

//Compression function: It is a function that maps a large set of inputs to a smaller set of outputs.

//Collision: It occurs when two different keys hash to the same index in a hash table.

//collision resolution: It is the process of handling the situation when two different keys hash to the same index in a hash table.
// for example: we have two strings: "abc" and "cba". Now if we apply the hash function on both of these strings, then we will get the same hash value for both of them.
// Now, if we store both of these strings in the same index of the hash table, then it will be a collision.
// There are two ways to resolve this collision:
// 1. Chaining: In this method, we store both of these strings in the same index of the hash table, but in the form of a linked list.
// 2. Open addressing: In this method, we store one of the strings in the same index of the hash table, and the other string in the next index of the hash table.

// linear probing: It is a method of open addressing in which we store the second string in the next index of the hash table.
// quadratic probing: It is a method of open addressing in which we store the second string in the next index of the hash table, but in the form of a quadratic equation.
// double hashing: It is a method of open addressing in which we store the second string in the next index of the hash table, but by using a different hash function.


