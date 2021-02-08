#ifndef __HASHTABLE_H
#define __HASHTABLE_H

typedef void* HashTable;
typedef void* HashData;
typedef void* InfoHash;

HashTable createHashTable(int tamHT);

void insertValueHashTable(HashTable ht, char* key, InfoHash value);

int isKeyHashTable(HashTable ht, char* key);

InfoHash getValue(HashTable ht, char* key);

void removeKey(HashTable ht, char* key);

void removeHashTable(HashTable ht);
     
int hashFunc(char* key, int tamHT);

#endif

