#include <iostream>
#include <list>
#include <string>

using namespace std;

// Hash table implementation using open addressing

class HashTable {
    int capacity;
    string *table;
    int *table1;

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
    int hashFunction2(string key) {
        int index, sum = 0;
        for (int i = 0; i < key.length(); i++)
        sum += (int)key[i];
        index = (sum + 1) % capacity;
        return index;
    }
    void displayHash();
};

HashTable::HashTable(int c) {
    int size = getPrime(c);
    this->capacity = size;
    table = new string[capacity];
    table1 = new int[capacity];
}

void HashTable::insertItem(string key, int data) {
    int index = hashFunction(key);
    if (table[index] == "") {
        table[index] = key;
        table1[index] = data;
    }
    else {
        int index2 = hashFunction2(key);
        int i = 1;
        while (1) {
            int newIndex = (index + i * index2) % capacity;
            if (table[newIndex] == "") {
                table[newIndex] = key;
                table1[newIndex] = data;
                break;
            }
            i++;
        }
    }
}

void HashTable::deleteItem(string key) {
    int index = hashFunction(key);
    if (table[index] == key) {
        table[index] = "";
        table1[index] = 0;
    }
    else {
        int index2 = hashFunction2(key);
        int i = 1;
        while (1) {
            int newIndex = (index + i * index2) % capacity;
            if (table[newIndex] == key) {
                table[newIndex] = "";
                table1[newIndex] = 0;
                break;
            }
            i++;
        }
    }
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
        if (table[i] != "")
        cout << "Index: " << i << " Key: " << table[i] << " Data: " << table1[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the hash table: ";
    cin >> n;
    HashTable h(n);
    int choice, value;
    string key;
    while (1) {
        cout << "1. Insert element into the table" << endl;
        cout << "2. Delete element at a key" << endl;
        cout << "3. Display Hash Table" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the key to be inserted: ";
                cin >> key;
                cout << "Enter the value to be inserted: ";
                cin >> value;
                h.insertItem(key, value);
                break;
            case 2:
                cout << "Enter the key of the element to be deleted: ";
                cin >> key;
                h.deleteItem(key);
                break;
            case 3:
                h.displayHash();
                break;
            case 4:
                exit(1);
            default:
                cout << "Enter a valid choice!" << endl;
        }
    }
    return 0;
}