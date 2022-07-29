#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HASH_SIZE 128


int hash(char key[]) {
    // Returns a number between 0 and HASH_SIZE depending on the key.

    int index = 0;
    // Loop over all of the key's characters
    for (int i = 0; i < strlen(key); i++) {
        index += (int) key[i]; // Get the current character's ASCII value and add it to index.
    }

    // Ensure that index is no larger than HASH_SIZE and return it.
    return index % HASH_SIZE;
}

void set_hash(char key[], char value[], char *hash_map[]) {
    int index = hash(key); // Get the index from this key.

    hash_map[index] = value; // Assign the index its value.
}

char* get_by_key(char key[], char *hash_map[]) {
    // Returns the value at the index returned by hash(key)
    return hash_map[hash(key)];
}

int main() {
    // Initialize an array that will store the hash map's values as strings.
    char* hash_map[HASH_SIZE] = {NULL};

    // Set some key/value pairs.
    set_hash("name", "john", hash_map);
    set_hash("age", "34", hash_map);
    set_hash("type", "human", hash_map);

    // Get and print the new values using their key.
    printf("name is %s\n", get_by_key("name", hash_map));
    printf("age is %s\n", get_by_key("age", hash_map));
    printf("type is %s\n", get_by_key("type", hash_map));


    return 0;
}