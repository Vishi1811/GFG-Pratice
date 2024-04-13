//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long res=0;
        for(int i=1;i<=32;i++)
        {
            long long lsb=x&1;
            long long revlsb=lsb<<(32-i);
            res=res | revlsb;
            x=x>>1;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends