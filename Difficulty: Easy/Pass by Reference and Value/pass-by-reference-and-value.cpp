//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        // code here
         a = a + 1;  // increment the value of a
        b = b + 2;  // increment the value of b
        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        Solution obj;
        vector<int> ans = obj.passedBy(a, b);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends