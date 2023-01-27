#ifndef HASHMAP__H__
#define HASHPMAP__H__
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
template <typename K, typename V>
class HashMap {
    struct Node {
        K key;
        V value;
        Node* next;
    };

    double maxLoadFactor;
    int numElements;
    int numBuckets;
    Node** buckets;

    size_t getBucketIndex(const K& key){
        return std::hash<K>{}(key) % numBuckets;
    }

    void resize(size_t newNumBuckets){
        std::vector<std::list<std::pair<K, V>>> newBuckets(newNumBuckets);
        for (auto& bucket : buckets){
            for (auto& [key, value] : bucket){
                newBuckets[getBucketIndex(key)].push_back({key, value});
            }
        }
        buckets = std::move(newBuckets);
                numBuckets = newNumBuckets;
    }


public:
    HashMap() : maxLoadFactor(0.7), numElements(0), numBuckets(8) {
        buckets = new Node*[numBuckets]();
    }

    ~HashMap() {
        for (int i = 0; i < numBuckets; i++) {
            Node* current = buckets[i];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] buckets;
    }

    void insert(const K& key, const V& value) {
        if (numElements + 1 > numBuckets * loadFactor){
                resize(numBuckets * 2);
        }
        buckets[getBucketIndex(key)].push_back({key, value});
        ++numElements;
    }

    V operator[](const K& key) {
        size_t index = hash(key) % bucketCount;
        auto& bucket = buckets[index];
        for (const auto& [k, v] : bucket) {
            if (k == key) {
                return v;
        }
    }
    return V();
    }

    V& operator[](const K& key) {
        size_t index = hash(key) % bucketCount;
        auto& bucket = buckets[index];
        for (auto& [k, v] : bucket) {
            if (k == key) {
                return v;
            }
        }
        bucket.emplace_back(key, V());
        ++count;
        if (count > loadFactor * bucketCount) {
            resize(bucketCount * 2);
        }
        return bucket.back().second;
    }
};


#endif