//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

// } Driver Code Ends
class Solution
{
  public:
    vector<int> findIndex(int arr[], int n, int key)
    {
        vector<int>ans;
        int e=-1,s=-1;
        for(int i=0;i<n;i++)
        {
            if(key==arr[i])
            {
               s=i;
               break;
            }
            
        }
        for(int i=s;i<n;i++)
        {
            if(key==arr[i])
            {
                e=i;
            }
        }
        ans.push_back(s);
        ans.push_back(e);
        return ans;
    }
  
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends