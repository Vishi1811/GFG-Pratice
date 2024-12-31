//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> nums(arr.begin(), arr.end()); // Use unordered_set for presence check
        int longest = 0;
    
        for (int num : nums) {
            // Check if it's the start of a sequence
            if (nums.find(num - 1) == nums.end()) {
                int currentNum = num;
                int currentStreak = 1;
    
                // Check for the next numbers in the sequence
                while (nums.find(currentNum + 1) != nums.end()) {
                    currentNum++;
                    currentStreak++;
                }
    
                // Update the longest sequence
                longest = max(longest, currentStreak);
            }
        }
    
        return longest;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends