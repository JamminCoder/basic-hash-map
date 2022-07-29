# Very Basic Hash Mapping in C

First, you create an array to store the hash map's values:
```c
char* hash_map[HASH_SIZE] = {NULL};
```

Then you can set and get values using keys:
```c
// Sets "key" to "value" in hash_map
set_hash("key", "value", hash_map);

// Get value at "key" from hash_map
get_by_key("key", hash_map);
```

