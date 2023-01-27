#include <iostream>
#include <string>
#include "hashmap.h"


int main() {
    HashMap<std::string, int> map;

    // Insert key-value pairs and check load factor
    for (int i = 1; i <= 10; i++) {
        std::string key = "key" + std::to_string(i);
        map.insert(key, i);
        double loadFactor = map.numElements / map.numBuckets;
        std::cout << "Inserted key '" << key << "', load factor: " << loadFactor << std::endl;
    }

    // Insert more key-value pairs and check number of buckets
    for (int i = 11; i <= 20; i++) {
        std::string key = "key" + std::to_string(i);
        map.insert(key, i);
        std::cout << "Inserted key '" << key << "', number of buckets: " << map.numBuckets << std::endl;
    }

    // Test retrieval of key-value pairs
    for (int i = 1; i <= 20; i++) {
        std::string key = "key" + std::to_string(i);
        int value = map[key];
        if (value == i) {
            std::cout << "Retrieved value for key '" << key << "' correctly: " << value << std::endl;
        } else {
            std::cout << "Error: Incorrect value for key '" << key << "': " << value << std::endl;
        }
    }

    // Test updating of key-value pairs
    for (int i = 1; i <= 20; i++) {
        std::string key = "key" + std::to_string(i);
        map[key] = i * 10;
    }
    for (int i = 1; i <= 20; i++) {
        std::string key = "key" + std::to_string(i);
        int value = map[key];
        if (value == i * 10) {
            std::cout << "Updated value for key '" << key << "' correctly: " << value << std::endl;
        } else {
            std::cout << "Error: Failed to update value for key '" << key << "': " << value << std::endl;
        }
    }
    return 0;
}