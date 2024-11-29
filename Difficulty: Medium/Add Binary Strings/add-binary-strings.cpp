//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int n=s1.size()-1;
        int m=s2.size()-1;
        int carry=0;
        string res="",ans="";
        while(n>=0 || m>=0 || carry==1)
        {
            carry+=(n>=0)?s1[n]-'0':0;
            carry+=(m>=0)?s2[m]-'0':0;
            res=char(carry%2+'0')+res;
            carry=carry/2;
            n--;
            m--;
        }
        int i=0;
        while(res[i]=='0')i++;
        if(i==res.size()-1)return "0";
        while(i<res.size())
        {
            ans+=res[i];
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends