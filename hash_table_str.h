#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent a hash table entry
typedef struct HashTableEntry {
    char* word;
    struct HashTableEntry* next;
} HashTableEntry;

// Structure to represent a hash table
typedef struct HashTable {
    int size;
    // List "Array" of pointers to Entries 
    HashTableEntry** table;    
} HashTable;

// Function to create a new hash table entry
HashTableEntry* createEntry(char* str) {
    HashTableEntry* newEntry = (HashTableEntry*) malloc(sizeof(HashTableEntry));
    newEntry->word = strdup(str);  // Duplicate the string
    newEntry->next = NULL;
    return newEntry;
}

// Function to create a new hash table
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (HashTableEntry**) malloc(sizeof(HashTableEntry*) * size);
    
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    
    return hashTable;
}

// Hash function to calculate hash code
unsigned int hashCode(HashTable* hashTable, char* str) {
    int charCount[26] = {0};  // Array to count occurrences of each character ('a' to 'z')

    // Count occurrences of each character in the input string
    for (int i = 0; str[i] != '\0'; i++) {
        charCount[str[i] - 'a']++;
    }

    // Compute a hash value from the character counts
    unsigned int hash = 0;
    for (int i = 0; i < 26; i++) {
        hash = hash * 31 + charCount[i];  // Use a prime number multiplier for hashing
    }

    return  hash % hashTable->size;  // Modulo operation to fit into the HashMap;
}

// Hash function to calculate hash code
unsigned long long hashNumber(char* str) {
    int charCount[26] = {0};  // Array to count occurrences of each character ('a' to 'z')

    // Count occurrences of each character in the input string
    for (int i = 0; str[i] != '\0'; i++) {
        charCount[str[i] - 'a']++;
    }

    // Compute a hash value from the character counts
    unsigned long long hash = 0;
    for (int i = 0; i < 26; i++) {
        hash = hash * 31 + charCount[i];  // Use a prime number multiplier for hashing
    }

    return  hash;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* hashTable, char* str) {
    int bucketIndex = hashCode(hashTable, str);

    // Create a new entry
    HashTableEntry* entry = createEntry(str);

    // Empty Bucket
    if (hashTable->table[bucketIndex] == NULL) {
        entry->next = NULL;
        hashTable->table[bucketIndex] = entry;

        return;
    }

    // Different Bucket    
    if (hashNumber(str) != hashNumber(hashTable->table[bucketIndex]->word)) {
        // Find the right bucket or an empty one
        int newIndex = -1;
        for (int i = 0; i < hashTable->size; i++) {
            // Found Empty Bucket
            if (hashTable->table[i] == NULL) {
                // Assign it to newIndex
                newIndex = i;
            } else if (hashNumber(str) == hashNumber(hashTable->table[i]->word)) {
                // Found the right bucket
                entry->next = hashTable->table[i];
                hashTable->table[i] = entry;

                // Assign the newIndex
                newIndex = i;

                break;    
            }
        }

        // Check if Found Empty Bucket
        if (hashTable->table[newIndex] == NULL) {
            entry->next = NULL;
            hashTable->table[newIndex] = entry;
        }
    } else {
        entry->next = hashTable->table[bucketIndex];
        hashTable->table[bucketIndex] = entry;
    }
}


// Function to free the hash table
void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        HashTableEntry* entry = hashTable->table[i];
        while (entry != NULL) {
            HashTableEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}