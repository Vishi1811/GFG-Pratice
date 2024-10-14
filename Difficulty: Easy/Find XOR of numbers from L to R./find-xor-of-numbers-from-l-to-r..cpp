//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int XOR(int n)
  {
      if(n%4==0)return n;
      if(n%4==3)return 0;
      if(n%4==2)return n+1;
      if(n%4==1)return 1;
  }
    int findXOR(int l, int r) {
        // complete the function here
        return XOR(l-1)^XOR(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends