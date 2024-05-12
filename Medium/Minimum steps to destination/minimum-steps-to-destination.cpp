//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
         int s = 0, sum = 0;
        while(true){
            sum = sum + s;
            s++;
            if(sum == d){
                return s-1;
                break;
            }
            if(sum > d and (sum-d)%2 == 0){
                return s-1;
                break;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends