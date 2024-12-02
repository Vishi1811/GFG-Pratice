//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string rev=s;
        int n=s.size();
        if(!n) return 0;
        reverse(rev.begin(),rev.end());
        string w= s + "*" + rev;
        int i=1, length=0, wn=w.size();
        vector<int>LPS(w.size());
        LPS[0]=0;
        while(i < wn){
            if(w[i]==w[length]) LPS[i++]=++length;
            else{
                if(length) length=LPS[length-1];
                else LPS[i++]=0;
            }
        }
        return n-LPS[w.size()-1];
   
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends