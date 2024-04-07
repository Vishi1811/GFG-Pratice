//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int rightMax[n];
        rightMax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1],arr[i]);
        }
        int ans = 0;
        int i=0, j=0;
        while(i<n and j<n)
        {
            if(rightMax[j] >= arr[i]){
                ans = max(ans,j-i);
                j++;
            }    
            else{
                i++;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends