//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        if(k>=arr[n-1])return arr[n-1];
        if(k<=arr[0])return arr[0];
        int l = 0,h = n-1;
        int dif = INT_MAX;
        int ans = arr[0];
        while(l<=h){
            //cout<<l<<" "<<h<<endl;
            int m = (l+h)/2;
            if(abs(arr[m]-k)<=dif){
                if(abs(arr[m]-k)==dif){
                    ans = max(ans,arr[m]);
                }
                else{
                    ans = arr[m];
                }
                dif = abs(arr[m]-k);
            }
            if(arr[m]>k){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
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
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends