#include <iostream>
#include <list>
#include <string>

using namespace std;
/*
This file contains the following:
1. Hash table implementation using chaining
2. insertItem function
3. deleteItem function
4. checkPrime function
5. getPrime function
6. hashFunction function
7. displayHash function
8. searching function

*/

class HashTable
{
    int capacity;
    list<int> *table;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    int checkPrime(int n);
    int getPrime(int n);

    int hashFunction(int key)
    {
        return (key % capacity); 
    }
    void displayHash();
    void searching(int key);
};

HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }
    if (i != table[index].end())
        table[index].erase(i);
}

int HashTable::checkPrime(int n)
{
    int i;
    if (n == 1 || n == 0)
        return 0;
    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int HashTable::getPrime(int n)
{
    if (n % 2 == 0)
        n++;
    while (!checkPrime(n))
        n += 2;
    return n;
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
void HashTable::searching(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            cout << "Element found at index " << index << " and key " << key << endl;
            break;
        }
    }
    if (i == table[index].end())
        cout << "Element not found" << endl;
}

int main()
{
    int key[] = {20,34,45,70,56,76,84};
    int n = sizeof(key) / sizeof(key[0]);
    HashTable h(7);
    for (int i = 0; i < n; i++)
    {
        h.insertItem(key[i], i + 1);
    }


    h.displayHash();
    cout<<endl;
    cout<<"After deleting 34"<<endl;
    h.deleteItem(34);
    h.displayHash();
    cout<<endl;

    cout<<"Searching for 45"<<endl;
    h.searching(45);
}
