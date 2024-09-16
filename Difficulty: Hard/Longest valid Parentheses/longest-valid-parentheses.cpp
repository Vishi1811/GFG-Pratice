//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int ans = 0;
        int open = 0,close = 0;
        for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {
            open++;
        } else {
            close++;
        }
        if(open == close) {
            ans = max(ans, 2 * close); // Valid substring
        } else if(close > open) {
            open = 0;
            close = 0;
        }
    }

    
    open = close = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        if(str[i] == ')') {
            close++;
        } else {
            open++;
        }
        if(open == close) {
            ans = max(ans, 2 * open); // Valid substring
        } else if(open > close) {
            open = 0;
            close = 0;
        }
    }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends