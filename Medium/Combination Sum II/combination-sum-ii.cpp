//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     void solve(int i,int curr,int n,int k,vector<int>&arr, vector<int>&temp,set<vector<int>>&ans){
        if(curr==k){
            ans.insert(temp);
            return;
        }
        if(i==n-1){
            if(arr[i]==(k-curr)){
                temp.push_back(arr[i]);
                ans.insert(temp);
                temp.pop_back();
                return;
            }
            else return;
        }
        
        if(curr+arr[i]<=k){
            temp.push_back(arr[i]);
            solve(i+1,curr+arr[i],n,k,arr,temp,ans);
            temp.pop_back();
        }
        solve(i+1,curr,n,k,arr,temp,ans);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<int>temp;
        set<vector<int>>ans;
        solve(0,0,n,k,arr,temp,ans);
        vector<vector<int>>ans2(ans.begin(),ans.end());
        return ans2;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends