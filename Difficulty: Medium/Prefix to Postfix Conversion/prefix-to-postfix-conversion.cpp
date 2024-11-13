//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        int i=pre_exp.size()-1;
        stack<string>st;
        while(i>=0)
        {
            if(iswalnum(pre_exp[i])) st.push(string(1, pre_exp[i]));
            else
            {
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                st.push(t1+t2+pre_exp[i]);
            }
            i--;
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends