//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size()-1;
        if(str[n]<='5'){
            str[n]='0';
            return str;
        }
        str[n]='0';
        n--;
        while(n>=0 and str[n]=='9'){
            str[n]='0';
            n--;
        }
        if(n==-1)return '1'+str;
        str[n]++;
        return str;
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
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends