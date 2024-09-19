//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
       int n = str.length();
        reverse(str.begin() , str.end());
        int i=0;
        int j=0;
        while(j<n){
            if(str[j]=='.'){
                reverse(str.begin()+i , str.begin()+j);
                i= j+1;
                j++;
            }
            else j++;
        }
        reverse(str.begin()+i , str.end());
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends