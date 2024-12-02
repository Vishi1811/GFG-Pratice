//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void findlps(vector<int>&lps,string s)
    {
        int n=lps.size();
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
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int m=pat.size();
        int n=txt.size();
        vector<int>lps(m);
        vector<int>ans;
        findlps(lps,pat);
        int first=0,second=0;
        while(first<n && second<m)
        {
           
            if(txt[first]==pat[second])
            {
                first++;
                second++;
            }
            else
            {
                if(second==0)first++;
                else second=lps[second-1];
            }
            if (second == m) {
            // Found a match
            ans.push_back(first - second); // Corrected index calculation
            second = lps[second - 1]; 
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends