//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
          vector<int>count(str.size(),0);
        int pre= 0, suff = 1;
        while(suff<str.size()){
            if(str[pre]==str[suff]){
                count[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    count[suff] = 0;
                    suff++;
                }
                else{
                    pre = count[pre-1];
                }
            }
        }
        
        return count[str.size()-1];
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

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends