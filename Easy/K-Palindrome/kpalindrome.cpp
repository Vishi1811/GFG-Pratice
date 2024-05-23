//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        // code here
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
               if(str[i]==str[j])
               {
                   mat[i+1][n-j]=1+mat[i][n-j-1];
               }
               else
               {
                   mat[i+1][n-j]=max(mat[i+1][n-j-1],mat[i][n-j]);
               }
            }
            
            
        }
        //cout<<arr[n]<<endl;
        int temp=mat[n][n];
        if(n-temp<=k)
        return 1;
        else
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends