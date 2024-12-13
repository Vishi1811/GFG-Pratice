//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n=arr.size();
        int low=0,high=n-1;
        int ans=INT_MAX;
         while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] > arr[high]) {
                // The minimum element must be in the right half
                low = mid + 1;
            } else if (arr[mid] < arr[high]) {
                // The minimum element must be in the left half
                high = mid;
            } else {
                // If arr[mid] == arr[high], we cannot decide the side
                // so we reduce the search space
                high--;
            }
        }
        
        // At the end of the loop, low == high and points to the minimum element
        return arr[low];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends