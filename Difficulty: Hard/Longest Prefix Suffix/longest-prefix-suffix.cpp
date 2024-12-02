//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        int n=s.size();
        vector<int>lps(n);
        int pre=0,suff=1;
        while(suff<n)
        {
            if(s[pre]==s[suff])
            {
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else
            {
                if(pre==0)
                {
                    lps[suff]=0;
                    suff++;
                }
                else
                {
                    pre=lps[pre-1];

                }
            }
        }
        return lps[n-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.longestPrefixSuffix(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends