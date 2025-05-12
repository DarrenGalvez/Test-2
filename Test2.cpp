#include <iostream>
using namespace std;

const int TABLE_SIZE = 11;
int hashTable[TABLE_SIZE];

// Function to initialize the table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable[i] = -1;  // empty
    }
}

// Division method hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            cout << "Hash table is full! Cannot insert key: " << key << endl;
            return;
        }
    }

    hashTable[index] = key;
    cout << "Inserted key " << key << " at index " << index << endl;
}

// Display the hash table
void displayTable() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << i << " --> ";
        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];
        cout << endl;
    }
}

int main() {
    initializeTable();

    int keys[] = {23, 43, 13, 27, 37};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; ++i) {
        insert(keys[i]);
    }

    displayTable();

    return 0;
}
