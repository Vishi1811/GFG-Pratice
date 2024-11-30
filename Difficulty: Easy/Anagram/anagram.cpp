//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;

        unordered_map<char, int> freq;

        // Increment for `s1` and decrement for `s2`
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i]]++;
            freq[s2[i]]--;
        }

        for (auto pair : freq) {
            if (pair.second != 0) return false;
        }

        return true;
        
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends