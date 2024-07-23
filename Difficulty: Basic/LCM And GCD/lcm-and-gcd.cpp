//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long>ans;
        long long lcm;
        long long x=A,y=B;
        while(x>0 && y>0)
        {
            if(x>y) x=x%y;
            else y=y%x;
        }
        if (x==0)
        {
            lcm=(A*B)/y;
            ans.push_back(lcm);
            ans.push_back(y);
        }
        else
        {
            lcm=(A*B)/x;
            ans.push_back(lcm);
            ans.push_back(x);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends