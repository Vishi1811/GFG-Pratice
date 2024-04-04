//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        const int M=1e9+7;
        int f[n+1];
        f[0]=0;
        f[1]=1;
        for(int i=2;i<=n;i++)
        {
            f[i]=(f[i-1]%M+f[i-2]%M)%M;
        }
        return f[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends