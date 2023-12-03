#include <iostream>
#include <list>
#include <string>

using namespace std;

// Hash table implementation using chaining

class HashTable {
  int capacity;
  list<string> *table;

public:
    HashTable(int V);
    void insertItem(string key, int data);
    void deleteItem(string key);
    int checkPrime(int n);
    int getPrime(int n);
    int hashFunction(string key) {
        int index, sum = 0;
        for (int i = 0; i < key.length(); i++)
        sum += (int)key[i];
        index = sum % capacity;
        return index;
    }
    void displayHash();
    };

HashTable::HashTable(int c) {
    int size = getPrime(c);
    this->capacity = size;
    table = new list<string>[capacity];
}

void HashTable::insertItem(string key, int data) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void HashTable::deleteItem(string key) {
    int index = hashFunction(key);
    list <string> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
        break;
    }
    if (i != table[index].end())
        table[index].erase(i);
}

int HashTable::checkPrime(int n) {
    int i;
    if (n == 1 || n == 0)
        return 0;
    for (i = 2; i < n / 2; i++) {
        if (n % i == 0)
        return 0;
    }
    return 1;
}

int HashTable::getPrime(int n) {
    if (n % 2 == 0)
        n++;
    while (!checkPrime(n))
        n += 2;
    return n;
}

void HashTable::displayHash() {
    for (int i = 0; i < capacity; i++) {
        cout << "table[" << i << "]";
        for (auto x : table[i])
        cout << " --> " << x;
        cout << endl;
    }
}

int main() {
    string key[] = {"India", "Germany", "Italy", "France", "U.S"};
    int n = sizeof(key) / sizeof(key[0]);
    HashTable h(7);
    for (int i = 0; i < n; i++)
        h.insertItem(key[i], i + 1);
        h.displayHash();
    h.deleteItem("Italy");
    h.displayHash();
}


