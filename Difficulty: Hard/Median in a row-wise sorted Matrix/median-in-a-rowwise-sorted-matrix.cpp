//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int upperBound(vector<int>&arr,int n,int x)
    {
        int ans = n;
        int low=0;
        int high=n-1;

        while (low <= high) {
            int mid = (low + high) / 2;
         
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int smallEqual(vector<vector<int>>&arr,int n,int m,int x)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=upperBound(arr[i],m,x);
        }
        return cnt;
    }
    int findMin(vector<vector<int>>&arr,int n,int m)
    {
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,arr[i][m]);
        }
        return mini;
    }
    int findMax(vector<vector<int>>&arr,int n,int m)
    {
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i][m]);
        }
        return maxi;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        int low=findMin(matrix,R,0);
        int high=findMax(matrix,R,C-1);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int req=(R*C)/2;
            int cnt=smallEqual(matrix,R,C,mid);
            if(cnt<=req)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends