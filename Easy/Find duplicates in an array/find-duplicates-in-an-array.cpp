//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
       vector<int> ans;
        unordered_map<int,int> hs;
        for(int i = 0; i < n; i++){
            if(hs[arr[i]] == 1){
                ans.push_back(arr[i]);
            }
            hs[arr[i]]++;
        }
        if(ans.size() > 0){
            sort(ans.begin(),ans.end());
            return ans;
        }
        else{
            return {-1};
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends