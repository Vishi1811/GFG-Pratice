//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
       vector<int>a,b;
       for(int i=0;i<n;i++){
           a.push_back(i*arr[i]);
           b.push_back(a[i]);
       }
       sort(b.begin(),b.end());
       int ans=0;
       for(int i=0;i<n;i++){
           int i1=lower_bound(b.begin(),b.end(),a[i])-b.begin();
           ans+=i1;
           b.erase(b.begin()+i1);
       }
       return ans;   
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends