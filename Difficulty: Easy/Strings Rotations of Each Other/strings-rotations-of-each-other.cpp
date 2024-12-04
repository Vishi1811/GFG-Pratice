//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
         s2 = s2 + s2;
        
        int i=0;
        int j=0;
        
        while(j<s1.size() and i<s2.size()){
            if(s1[j] == s2[i]){
                i++;
                j++;
            }
            else{
                // cout<<s1[j]<<j<<" "<<s2[i]<<i<<endl;
                if(j!=0)    j=0;
                else i++;
            }
            
            if(j>=s1.size()) return true;
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends