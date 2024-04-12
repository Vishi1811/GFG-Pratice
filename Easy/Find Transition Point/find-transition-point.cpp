//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        int s=0,e=n-1;
       
        if(arr[0]==1)
        {
            return 0;
        }
        while(s<e)
        {
            int m=s+(e-s)/2;
            if(arr[m]==0 && arr[m+1]==1)
            {
                return m+1;
                
            }
            else if(arr[m]==1 && arr[m-1]==0)
            {
                return m;
            }
            else if(arr[m]==0)
            {
                s=m+1;
            }
            else
            {
                e=m-1;
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends