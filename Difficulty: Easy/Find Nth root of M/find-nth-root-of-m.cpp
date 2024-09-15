//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	//if  mid^n >m return 1;
    //if mid^n==m return 2;
    //if mid^n<m return 0;
    int Power (int mid,int n,int m){
          long long ans=1;
          for (int i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m)
              return 1;
            }
          if(ans==m) return 2;
          return 0;
    }
	int NthRoot(int n, int m)
	{
         int low=1;
         int high=m;
         while(low<=high)
         {
            int mid=low+(high-low)/2;
            if(Power(mid,n,m)==2)return mid;
            else if(Power(mid,n,m)==1) high=mid-1;
            else low=mid+1;
         }
         return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends