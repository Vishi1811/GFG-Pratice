//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        int n=exp.size();
        int i=0;
        while(i<n)
        {
            if(iswalnum(exp[i]))
            {
                st.push(string(1,exp[i]));
            }
            else
            {
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                st.push("(" + t2 + exp[i] + t1 + ")");

            }
            i++;
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends