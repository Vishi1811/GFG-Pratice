//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        string result = ""; // To store the final string
        int n = s.size();
        
        if (n == 0) return result; // Handle empty string case
        
        result += s[0]; // First character is always added
        
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) { // Only add the character if it's different from the previous one
                result += s[i];
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends