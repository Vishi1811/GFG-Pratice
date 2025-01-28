//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void fun(string s,int n,set<string>&ans,int ind){
        if(ind==n){
            ans.insert(s);
            return;
        }
        for(int i=ind;i<=n;i++){
            swap(s[i],s[ind]);
            fun(s,n,ans,ind+1);
            swap(s[i],s[ind]);
        }
        
    }
    vector<string> findPermutation(string &s) {
        int n=s.size();
        set<string>ans;
        int ind=0;
        fun(s,n-1,ans,ind);
        vector<string>res(ans.begin(),ans.end());
        return res;
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends