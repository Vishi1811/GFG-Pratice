//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
         if(n==k) return 0;
        vector<pair<int,int>> p;
        vector<pair<int,int>> s;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n-k;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
            p.push_back({maxi,mini});
        }
        maxi=INT_MIN;
        mini=INT_MAX;
        for(int i=n-1;i>=k;i--){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
            s.push_back({maxi,mini});
        }
        reverse(s.begin(),s.end());
        int m=s.size();
        int ans=s[0].first-s[0].second;
        for(int i=0;i<m-1;i++)
        {
            maxi=max(s[i+1].first,p[i].first);
            mini=min(s[i+1].second,p[i].second);
            ans=min(ans,maxi-mini);
        }
        ans=min(ans,p[m-1].first-p[m-1].second);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends