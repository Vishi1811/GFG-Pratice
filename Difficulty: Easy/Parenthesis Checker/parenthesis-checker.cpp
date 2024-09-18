//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
         stack<char> st;
        unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for (char c : x) {
            if (mp.count(c))
                if (!st.empty() && st.top() == mp[c]) {
                    st.pop();
                    continue;
                }
            st.push(c);
        }
        
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends