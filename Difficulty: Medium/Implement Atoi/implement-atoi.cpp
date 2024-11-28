//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
       int n = strlen(s);
        int sign=1;
        int ans=0;
        int i = 0;
        while (i < n && s[i] == ' ')i++;
        
        // Handle optional '+' or '-' sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
    
        
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
    
            // Check for overflow
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
    
            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends