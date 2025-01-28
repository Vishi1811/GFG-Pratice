//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class LRUCache {
private:
    int cap; // capacity of cache
    list<int> dll;  // Doubly Linked List to store keys in the order of use
    unordered_map<int, pair<list<int>::iterator, int>> mp;  // key -> (iterator to the key in dll, value)

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity) {
        cap = capacity;
    }

    // Function to make the key as recently used.
    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);  // Remove the key from its current position
        dll.push_back(key);  // Add it to the end (most recently used)
        mp[key].first = --dll.end();  // Update the iterator in the map
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // If the key is not found, return -1
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        // Make the key recently used and return its value
        makeRecentlyUsed(key);
        return mp[key].second;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            // If the key is not already present, check if the cache is full
            if (dll.size() == cap) {
                // Cache is full, remove the least recently used (LRU) element
                int oldKey = dll.front();
                dll.pop_front();
                mp.erase(oldKey);  // Remove the LRU element from the map
            }
            // Add the new key-value pair
            dll.push_back(key);  // Add to the end of the list (most recently used)
            mp[key] = {--dll.end(), value};  // Store the iterator and value in the map
        } else {
            // If the key is already present, update its value and make it recently used
            makeRecentlyUsed(key);
            mp[key].second = value;  // Update the value of the existing key
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends