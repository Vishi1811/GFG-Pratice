//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int len=0;
        int prefixSum=0;
        map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<N;i++)
        {
            prefixSum+=A[i];
            if(mp.find(prefixSum-K)!=mp.end())
            {
                len=max(len,(i-mp[prefixSum-K]));
            }
            if(mp.find(prefixSum) == mp.end()) 
            {
                mp[prefixSum] = i;
            }
        }
        return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends